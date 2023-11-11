# audioDebugger
audioDebugger is a audio analysis tool developed for debugging audio related code used in RoboCup. If the tool is to be used by other teams, this project should be considered as a contribution by the RoboÉireann team.

# Motivation
As more and more developments in the RoboCup rules are trying to eliminate dependence on wireless forms of communication to each robot and by the Game Controller, audio is one of the next areas of development by teams, especially through Whistle Detectors and encoded signals through audio transmission. This tool aims to conveniently provide utility in analyzing obtained audio data.

# Requirements & Dependencies
As of this current state, there are several external libraries that are used for building this code. Your mileage may vary if you plan to build on non-arch based or non-rolling release distributions.

The current state of the machine used in compiling this code:
- Arch Linux
- Plasma (Wayland)
- fmt library from the [AUR](https://aur.archlinux.org/packages/fmt-git)
- Audio provided by PipeWire (`pipewire, pipewire-pulse, pipewire-jack, wireplumber`)

Dependencies include (but does not include all their depdendencies):
- [Dear ImGUI](https://github.com/ocornut/imgui)
- [ImPlots](https://github.com/epezent/implot)
- [FFTW3](https://fftw.org/)
- [miniaudio](https://github.com/mackron/miniaudio)
  - Depends on JACK & ALSA

These 
You can install some of the required packages, via Pacman:
```bash
# pacman -S base-devel fftw glfw-wayland fmt alsa-lib
```

# Building
Building is done through the makefile, with a simple `make`, with the executable located in `build`.

# Licences
- Audio in the `assets/audioSamples` directory are licensed with the CC-BY-NC-SA 3.0 license.
- Josefin Sans font is licensed with the OFL license.
