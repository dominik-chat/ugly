# ugly

![LICENSE](https://img.shields.io/github/license/dominik-chat/ugly?style=flat-square)
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fdominik-chat%2Fugly.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2Fdominik-chat%2Fugly?ref=badge_shield)
![LOC](https://img.shields.io/tokei/lines/github/dominik-chat/ugly?style=flat-square)

Ugly is a GUI library can be used to create a simple user interface.
The library uses SDL2 as a graphics library.

## Compilation

The program requires a C compiler, [cmake](https://cmake.org/) and [SDL2](https://www.libsdl.org/) library.

The compilation compilation of the library can be performed in the `lib` directory:
```
cmake -S. -Bbuild
cd build
make
```

The library can be installed using this command:
```
make install
```
**Note that you may be required to execute this command as a superuser**
