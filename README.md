# CS2-Surf
## Description
An open source plugin for surfing in CS2.

## Status: Preparation
This repository is being created in preparation for the release of CS2.

## Installation
Run to following commands to build this plugin.
1. `git submodule update --init --recursive`
1. `python -m venv .venv`
2. `.\.venv\Scripts\Activate.ps1`
3. `.\install.bat`
6. `mkdir build`
7. `cd .\build\`
8. `python ..\configure.py --plugin-name "sample_mm" --plugin-alias "sample" --hl2sdk-root "..\" --hl2sdk-manifests ".\metamod-source\hl2sdk-manifests\" --mms_path "..\metamod-source\" --sdks "cs2" --targets "x86_64"`
