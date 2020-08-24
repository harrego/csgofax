# csgofax

Keep your CSGO team informed what's playing 

## Usage

### Requirements

- Linux
- glib/gobject 2.0
- libxdo

`make run`

## How it works

It uses `mpris` to determine the current song playing and then types `say Now playing: TITLE by ARTIST` into the CSGO console. Before a song changes make sure you are standing still or you may type bad input into the console!

## Contributions

Thanks to [chxrlt](https://github.com/chxrlt) for the `mpris` and the `xdo` idea to get this running.

## Disclaimer

CSGO is a multiplayer video game with an anti-cheat. Like all applications that interact with the game it may lead to a "cheat detection" and get you banned. This IS NOT a cheat but it is always unknown what will trigger anti-cheat. Run this tool AT YOUR OWN RISK and I am not responsible for any action as a result of using this tool.