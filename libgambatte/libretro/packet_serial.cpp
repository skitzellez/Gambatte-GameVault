/* Copyright (c) 2026 Skitzelles - part of Game Vault, https://github.com/skitzellez/xbox-game-vault
 * GPL-2.0-or-later, like Gambatte.
 *
 * See packet_serial.h. A packet is 3 bytes: kind (1 = a byte from the clocking Game Boy, 2 = the answer), the
 * byte, and the fast-CGB flag Gambatte's network link passes along.
 */
#include "packet_serial.h"
#include "gambatte_log.h"

#include <time.h>

/* how long the clocking Game Boy waits for the other's byte: a link cable with nothing at the other end reads
 * 0xFF, and games treat that as "no partner" */
#define ANSWER_WAIT_MS 3000

void PacketSerial::start(uint16_t own_id, retro_netpacket_send_t send_fn, retro_netpacket_poll_receive_t poll_fn)
{
   send_fn_ = send_fn;
   poll_fn_ = poll_fn;
   host_    = own_id == 0;
   peer_    = host_ ? -1 : 0;
   queue_.clear();
   gambatte_log(RETRO_LOG_INFO, "[link] online link cable on (%s)\n", host_ ? "host" : "joined");
}

void PacketSerial::stop()
{
   send_fn_ = NULL;
   poll_fn_ = NULL;
   peer_    = -1;
   queue_.clear();
   gambatte_log(RETRO_LOG_INFO, "[link] online link cable off\n");
}

bool PacketSerial::connect(uint16_t client_id)
{
   if (peer_ >= 0)
      return false;   /* the cable's other end is taken: no third player */
   peer_ = client_id;
   queue_.clear();
   gambatte_log(RETRO_LOG_INFO, "[link] the other Game Boy is plugged in\n");
   return true;
}

void PacketSerial::disconnect(uint16_t client_id)
{
   if (peer_ != client_id)
      return;
   peer_ = -1;
   queue_.clear();
   gambatte_log(RETRO_LOG_INFO, "[link] the other Game Boy left\n");
}

void PacketSerial::receive(const void* buf, size_t len, uint16_t client_id)
{
   const unsigned char* p = (const unsigned char*)buf;
   if (len < 3 || (host_ && (int)client_id != peer_))
      return;
   Byte b = { p[0], p[1], p[2] };
   queue_.push_back(b);
   static int logged = 0;
   if (logged < 6 && ++logged)
      gambatte_log(RETRO_LOG_INFO, "[link] got kind %u byte %02X from %u\n", p[0], p[1], client_id);
}

void PacketSerial::put(unsigned char kind, unsigned char data, unsigned char fast)
{
   unsigned char buf[3] = { kind, data, fast };
   static int logged = 0;
   if (logged < 6 && ++logged)
      gambatte_log(RETRO_LOG_INFO, "[link] sent kind %u byte %02X to %d\n", kind, data, peer_);
   send_fn_(RETRO_NETPACKET_RELIABLE | RETRO_NETPACKET_FLUSH_HINT, buf, sizeof(buf), (uint16_t)peer_);
}

bool PacketSerial::take(unsigned char kind, Byte& b)
{
   for (std::deque<Byte>::iterator it = queue_.begin(); it != queue_.end(); ++it)
      if (it->kind == kind)
      {
         b = *it;
         queue_.erase(it);
         return true;
      }
   return false;
}

unsigned char PacketSerial::send(unsigned char data, bool fastCgb)
{
   if (!send_fn_ || peer_ < 0)
      return 0xFF;

   /* an answer that came after an earlier wait gave up belongs to nothing now */
   for (std::deque<Byte>::iterator it = queue_.begin(); it != queue_.end();)
      it = it->kind == 2 ? queue_.erase(it) : it + 1;

   put(1, data, fastCgb ? 1 : 0);

   clock_t until = clock() + (clock_t)((long long)ANSWER_WAIT_MS * CLOCKS_PER_SEC / 1000);
   Byte b;
   while (!take(2, b))
   {
      if (!send_fn_ || peer_ < 0 || clock() > until)
      {
         static int logged = 0;
         if (logged < 3 && ++logged)
            gambatte_log(RETRO_LOG_WARN, "[link] no answer from the other Game Boy\n");
         return 0xFF;
      }
      poll_fn_();
   }
   static unsigned long count = 0;
   static clock_t since = 0;
   if (count++ % 500 == 0)
   {
      if (count > 1)
         gambatte_log(RETRO_LOG_INFO, "[link] 500 bytes in %ld ms\n",
                      (long)((clock() - since) * 1000 / CLOCKS_PER_SEC));
      since = clock();
   }
   return b.data;
}

bool PacketSerial::check(unsigned char out, unsigned char& in, bool& fastCgb)
{
   if (!send_fn_ || peer_ < 0)
      return false;
   Byte b;
   if (!take(1, b))
   {
      poll_fn_();
      if (!take(1, b))
         return false;
   }
   in      = b.data;
   fastCgb = b.fast != 0;
   put(2, out, 128);
   return true;
}
