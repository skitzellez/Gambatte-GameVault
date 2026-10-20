/* Copyright (c) 2026 Skitzelles - part of Game Vault, https://github.com/skitzellez/xbox-game-vault
 * GPL-2.0-or-later, like Gambatte.
 *
 * The Game Boy link cable through RetroArch's online rooms (the netpacket interface), so two players link with
 * their own games and their own saves - Pokemon Red with Pokemon Blue - with no address or port to type.
 * It works like Gambatte's own network link (net_serial.cpp): a byte the clocking Game Boy sends waits for the
 * other Game Boy's byte in return. Only the transport differs.
 */
#ifndef _PACKET_SERIAL_H
#define _PACKET_SERIAL_H

#include <gambatte.h>
#include <stddef.h>
#include <stdint.h>
#include <deque>

#include <libretro.h>

/* RETRO_ENVIRONMENT_SET_NETPACKET_INTERFACE, from RetroArch's libretro.h (this copy of libretro.h predates it) */
#ifndef RETRO_ENVIRONMENT_SET_NETPACKET_INTERFACE
#define RETRO_ENVIRONMENT_SET_NETPACKET_INTERFACE 78
#define RETRO_NETPACKET_UNRELIABLE  0
#define RETRO_NETPACKET_RELIABLE    (1 << 0)
#define RETRO_NETPACKET_UNSEQUENCED (1 << 1)
#define RETRO_NETPACKET_FLUSH_HINT  (1 << 2)
#define RETRO_NETPACKET_BROADCAST 0xFFFF
typedef void (RETRO_CALLCONV *retro_netpacket_send_t)(int flags, const void* buf, size_t len, uint16_t client_id);
typedef void (RETRO_CALLCONV *retro_netpacket_poll_receive_t)(void);
typedef void (RETRO_CALLCONV *retro_netpacket_start_t)(uint16_t client_id, retro_netpacket_send_t send_fn,
                                                      retro_netpacket_poll_receive_t poll_receive_fn);
typedef void (RETRO_CALLCONV *retro_netpacket_receive_t)(const void* buf, size_t len, uint16_t client_id);
typedef void (RETRO_CALLCONV *retro_netpacket_stop_t)(void);
typedef void (RETRO_CALLCONV *retro_netpacket_poll_t)(void);
typedef bool (RETRO_CALLCONV *retro_netpacket_connected_t)(uint16_t client_id);
typedef void (RETRO_CALLCONV *retro_netpacket_disconnected_t)(uint16_t client_id);
struct retro_netpacket_callback
{
   retro_netpacket_start_t        start;
   retro_netpacket_receive_t      receive;
   retro_netpacket_stop_t         stop;
   retro_netpacket_poll_t         poll;
   retro_netpacket_connected_t    connected;
   retro_netpacket_disconnected_t disconnected;
   const char* protocol_version;
};
#endif

class PacketSerial : public gambatte::SerialIO
{
   public:
      /* a session started (RetroArch's netpacket start): own id, 0 = the host */
      void start(uint16_t own_id, retro_netpacket_send_t send_fn, retro_netpacket_poll_receive_t poll_fn);
      void stop();
      bool active() const { return send_fn_ != NULL; }
      /* host only: the one other player (a link cable has two ends) */
      bool connect(uint16_t client_id);
      void disconnect(uint16_t client_id);
      void receive(const void* buf, size_t len, uint16_t client_id);

      virtual bool check(unsigned char out, unsigned char& in, bool& fastCgb);
      virtual unsigned char send(unsigned char data, bool fastCgb);

   private:
      struct Byte { unsigned char kind, data, fast; };
      bool take(unsigned char kind, Byte& b);
      void put(unsigned char kind, unsigned char data, unsigned char fast);

      retro_netpacket_send_t send_fn_ = NULL;
      retro_netpacket_poll_receive_t poll_fn_ = NULL;
      bool host_ = false;
      int peer_ = -1;            /* host: the client's id; client: 0, the host */
      std::deque<Byte> queue_;
};

#endif
