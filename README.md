# Game Boy Pong

A classic Pong game recreated for the original Nintendo Game Boy. Written in C and built using [GBDK](https://github.com/gbdk-2020/gbdk-2020).

<p align="center">
  <img src="images/IMG_20250507_050652.jpg" alt="Game Boy Pong Screenshot" width="550"/>
</p>

## Getting Started

### Requirements

- [GBDK (Game Boy Development Kit)](https://github.com/gbdk-2020/gbdk-2020)
- A Game Boy emulator like **BGB**, **SameBoy**, or a real Game Boy + flasher

## Building the Game
### Windows

1. **Install GBDK**  
   Download and extract [GBDK](https://github.com/gbdk-2020/gbdk-2020/releases) to a folder, e.g., `C:\gbdk`.

2. **Compile the Game**  
   A build script is included for Windows users: `make.bat` must run inside the game's directory.

   #### make.bat contents:
   ```bat
    c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o main.o main.c
    c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o main.gb main.o
### Linux

1. **Install GBDK**
Similar to Windows, download the Linux binary from [GBDK](https://github.com/gbdk-2020/gbdk-2020/releases) to a folder, e.g, `/home/your_user/gbdk/bin/lcc` replace `your_user` with your actual user account name.

2. **Compile the Game**  
Then open a terminal and run this inside the source code folder, again replace `your_user` with your actual user account name.

   ```bash
    /home/your_user/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o main.o main.c
    /home/your_user/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o main.gb main.o  

## 📦 Play or Download

You can also download the ROM or leave feedback on **Game Jolt**:

[![Game Jolt](https://img.shields.io/badge/Game%20Jolt-Play%20Now-yellowgreen?logo=gamejolt)](https://gamejolt.com/games/pong_gameboy/502976)
