# CS2-Surf

## Description

An open source plugin for surfing in CS2.

## Status

Custom AMBuilder scripts have been created and the sample plugin source code can be compiled. Beginning work on the actual plugin now.

## Building This Plugin

Run to following commands to build this plugin.

1. `python -m venv .venv`
2. `.\.venv\Scripts\Activate.ps1`
3. `.\install.bat`
4. `python .\configure.py --out build`
5. `cd .\build\`
6. `ambuild`

## Installation

To install this plugin on a server, copy the `addons` folder in the `.\\build\\package` directory and paste it in csgo directory where the metamod installation should already exist.
