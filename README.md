# Fluid Simulation

This program aims to be a highly optimised fluid simulation built in C++. In the process I hope to learn about how to write performant code better.

![Build](https://github.com/EepyKitty/FluidSim/actions/workflows/build.yml/badge.svg)

## Supported platforms

Tested on Linux (Arch), macOS, and Windows. Should work on any platform with the listed prerequisites.

## Build

### Prerequisites
 
- CMake 3.28+
- A C++23 compiler (GCC 13+, Clang 17+, or MSVC 19.38+)
- Ninja
- Git

**Linux:**
 
```
sudo pacman -S cmake ninja git base-devel                # Arch
sudo apt install cmake ninja-build git build-essential   # Debian / Ubuntu
```
 
**macOS:** install [Homebrew](https://brew.sh), then:
 
```
xcode-select --install
brew install cmake ninja git
```
 
**Windows:** install [Visual Studio 2022 Community](https://visualstudio.microsoft.com/downloads/) with the "Desktop development with C++" workload, then:
 
```
winget install Kitware.CMake Ninja-build.Ninja Git.Git
```
 
### Build
 
```
git clone <your-repo-url>
cd fluidsim
cmake -S . -B build -G Ninja
cmake --build build
./build/fluidsim
```
