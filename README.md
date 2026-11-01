<p align="center">
  <a href="https://github.com/skitzellez/xbox-game-vault"><img src="https://raw.githubusercontent.com/skitzellez/xbox-game-vault/main/GameVault/art/logo-banner.png" alt="Game Vault" width="640"></a>
</p>

<h1 align="center">Gambatte for Game Vault</h1>

<p align="center">
  <b>Game Boy and Game Boy Color with a working link cable, online.</b><br>
  The Gambatte core for RetroArch, built for <a href="https://github.com/skitzellez/xbox-game-vault">Game Vault</a>: two players trade and battle over the link cable in Game Vault's online rooms.
</p>

<!-- gv-buttons:start -->
<p align="center">
  <a href="https://github.com/skitzellez/Gambatte-GameVault/releases/latest"><img alt="DOWNLOAD Gambatte" src="https://img.shields.io/badge/DOWNLOAD-Gambatte-107C10?style=for-the-badge&logo=xbox&logoColor=white"></a>
  &nbsp;
  <a href="https://github.com/skitzellez/xbox-game-vault"><img alt="Get Game Vault" src="https://img.shields.io/badge/GET-Game%20Vault-107C10?style=for-the-badge&logo=xbox&logoColor=white"></a>
  &nbsp;
  <a href="https://discord.gg/RmhhWgguvw"><img alt="Join the Game Vault Discord" src="https://img.shields.io/badge/JOIN-Discord-5865F2?style=for-the-badge&logo=discord&logoColor=white"></a>
  &nbsp;
  <a href="https://www.patreon.com/Skitzelles"><img alt="Support on Patreon" src="https://img.shields.io/badge/SUPPORT-Patreon-F96854?style=for-the-badge&logo=patreon&logoColor=white"></a>
</p>
<!-- gv-buttons:end -->

> [!IMPORTANT]
> This is an **unofficial build**. It is not made or supported by libretro, so please report problems with it
> **here or on the [Game Vault Discord](https://discord.gg/RmhhWgguvw)**, not to them.

## 🚀 Getting started

Nothing to install by hand: **[Game Vault](https://github.com/skitzellez/xbox-game-vault)** and
**[Game Vault for Android](https://github.com/skitzellez/game-vault-android)** download this core when you open an online room for a Game Boy game.

<!-- gv-family:start -->
## 🎮 The Game Vault family

Game Vault is one launcher plus emulators built to work with it. **Install [Game Vault](https://github.com/skitzellez/xbox-game-vault) and it sets these up for you**; press **RT** in Game Vault to update them all.

**Apps**

| Project | What it is | Runs on |
|---|---|---|
| [Game Vault](https://github.com/skitzellez/xbox-game-vault) | The launcher: plug in a USB drive, pick a game, play. Sets up everything below by itself. | Xbox Series X&#124;S |
| [Game Vault for Android](https://github.com/skitzellez/game-vault-android) | The same game library for phones, tablets and Android TV (beta). | Android |
| [Game Vault for iPhone](https://github.com/skitzellez/game-vault-ios) | The Game Vault look on iPhone (early test). | iPhone |

**Emulators built for Game Vault**

| Project | What it is | Runs on |
|---|---|---|
| [xemu for Xbox Dev Mode](https://github.com/skitzellez/xemu-uwp) | Original Xbox | Xbox Series X&#124;S |
| [Xenia for Game Vault](https://github.com/skitzellez/Xenia-GameVault) | Xbox 360 | Xbox Series X&#124;S |
| [XBSX2 for Game Vault](https://github.com/skitzellez/XBSX2-GameVault) | PlayStation 2 | Xbox Series X&#124;S |
| [Dolphin for Game Vault](https://github.com/skitzellez/Dolphin-GameVault) | GameCube and Wii | Xbox Series X&#124;S |
| [Game Vault · Wii U (Cemu)](https://github.com/skitzellez/Cemu-GameVault) | Wii U | Xbox Series X&#124;S |
| [RetroArch for Game Vault](https://github.com/skitzellez/RetroArch-GameVault) | PlayStation, Dreamcast, arcade and classic systems | Xbox Series X&#124;S, Android |
| [Game Vault · Flash](https://github.com/skitzellez/Flash-GameVault) | Flash games | Xbox Series X&#124;S |
| [**Gambatte for Game Vault**](https://github.com/skitzellez/Gambatte-GameVault) 📍 *you are here* | Game Boy link cable in online rooms | Xbox Series X&#124;S, Android |
| [X1 BOX for Game Vault](https://github.com/skitzellez/x1box-gamevault) | Original Xbox | Android |

**Extras**

| Project | What it is | Runs on |
|---|---|---|
| [Free games](https://github.com/skitzellez/game-vault-free-games) | Freeware and shareware for the FREE GAMES tab | Game Vault |
| [Fallout 1in2 for Xbox](https://github.com/skitzellez/Fallout1in2-Xbox) | The original Fallout, made for the controller | Xbox Series X&#124;S |
| [Game Vault updates](https://github.com/skitzellez/game-vault-updates) | Update data Game Vault reads when it starts | Game Vault |

**💬 Help, news and bug reports:** the [Game Vault Discord](https://discord.gg/RmhhWgguvw) (or this repo's Issues).
Please don't take problems with these builds to the original emulator teams: they don't make or support them.
<!-- gv-family:end -->

## ❤️ Support

Game Vault and its emulators are free and stay free. If you'd like to help, you can support it on **[Patreon](https://www.patreon.com/Skitzelles)**. ❤️

## 📜 Credits and licence

Based on **[gambatte-libretro](https://github.com/libretro/gambatte-libretro)** (Gambatte by Sindre Aamås and contributors), GPL-2.0: see [COPYING](COPYING).
Game Vault changes by **[Skitzelles](https://github.com/skitzellez)**.

---

<details>
<summary><b>gambatte-libretro</b> (the original project's README)</summary>

[![Build Status](https://travis-ci.org/libretro/gambatte-libretro.svg?branch=master)](https://travis-ci.org/libretro/gambatte-libretro)
[![Build status](https://ci.appveyor.com/api/projects/status/tejf7jniu1imotag/branch/master?svg=true)](https://ci.appveyor.com/project/bparker06/gambatte-libretro/branch/master)

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
Copyright (C) 2007 by Sindre Aamås
aamas@stud.ntnu.no

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License version 2 for more details.

You should have received a copy of the GNU General Public License
version 2 along with this program; if not, write to the
Free Software Foundation, Inc.,
59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

About
--------------------------------------------------------------------------------
Gambatte is an accuracy-focused, open-source, cross-platform
Game Boy Color emulator written in C++. It is based on hundreds of
corner case hardware tests, as well as previous documentation and reverse
engineering efforts.

The core emulation code is contained in a separate library back-end
(libgambatte) written in platform-independent C++. There is currently a GUI
front-end (gambatte_qt) using Trolltech's Qt4 toolkit, and a simple command-line
SDL front-end (gambatte_sdl).

The GUI front-end contains platform-specific extensions for video, sound and
timers. It should work on MS Windows, Linux/BSD/UNIX-like OSes, and Mac OS X.

The SDL front-end should be usable on all platforms with a working SDL port. It
should also be quite trivial to create new (simple) front-ends (note that the
library API should in no way be considered stable).

Usage
--------------------------------------------------------------------------------
You will have to supply Gambatte with a ROM image file of the GB/GBC
program/game you'd like to run/play, either as a command-line argument to
gambatte_sdl, or through the File->Open... menu in gambatte_qt.

gambatte_sdl keyboard commands:
TAB    - fast-forward
Ctrl-f - toggle full screen
Ctrl-r - reset
F5     - save state
F6     - previous state slot
F7     - next state slot
F8     - load state
0 to 9 - select state slot 0 to 9

Default key mapping:
Up:     Up
Down:   Down
Left:   Left
Right:  Right
A:      D
B:      C
Start:  Return
Select: Shift

Compiling
--------------------------------------------------------------------------------
Building Gambatte from source code can be done by executing the
build_<qt/sdl>.sh scripts for the qt/sdl front-ends respectively, or by issueing
the correct build command (either 'scons' or 'qmake && make') in the top-level
subdirectories (libgambatte will have to be built first). The clean.sh script
can be executed to remove all generated files after a compile (including
binaries).

Requirements for building libgambatte:
- A decent C++ compiler (like g++ in the GNU Compiler Collection).
- SCons.
- optionally zlib

Requirements for building gambatte_sdl:
- A decent C++ compiler (like g++ in the GNU Compiler Collection).
- SDL headers and library.
- SCons.
(- libgambatte.)

Requirements for building gambatte_qt:
- A decent C++ compiler (like g++ in the GNU Compiler Collection).
- Qt4 (Core, GUI, OpenGL) headers and library.
- Qmake and make (GNU Make should work).
- Platform-specific requirements:
  * MS Windows:
    - Win32 API headers and libraries.
    - DirectSound and DirectDraw7 headers and libraries.
    - Direct3D9 headers
  * Linux/BSD/UNIX-like OSes:
    - POSIX/UNIX headers (unistd.h, fcntl.h, sys/ioctl.h, sys/time.h, sys/shm.h).
    - Open Sound System header (sys/soundcard.h).
    - X11 Xlib, XVideo, XRandR and XShm headers and libraries.
    - Alsa headers and library (Linux only).
  * Max OS X:
    - Recent Mac OS X SDK (Panther Xcode/SDK should work)
(- libgambatte.)

Installing after a compile simply amounts to copying the generated binary
(either gambatte_qt/bin/gambatte_qt<.exe> or gambatte_sdl/gambatte_sdl<.exe>)
to wherever you'd like to keep it.

Thanks
--------------------------------------------------------------------------------
Derek Liauw Kie Fa (Kreed)
Gilles Vollant
Jeff Frohwein
Jonathan Gevaryahu (Lord Nightmare)
kOOPa
Marat Fayzullin
Martin Korth (nocash)
Maxim Stepin (MaxSt)
Nach
Pan of Anthrox
Pascal Felber
Paul Robson
SDL
Shay Green (blargg)
The OpenGL Extension Wrangler Library

--------------------------------------------------------------------------------
Game Boy and Game Boy Color are registered trademarks of
Nintendo of America Inc.
Gambatte is not affiliated with or endorsed by any of the companies mentioned.

</details>
