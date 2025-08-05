#!/bin/bash

OS_NAME=`uname -o 2>/dev/null || uname -s`

if [ $OS_NAME == "Msys" ] || [ $OS_NAME == "MS/Windows" ]; then
    GLFLAG="-lopengl32"
elif [ $OS_NAME == "Darwin" ]; then
    GLFLAG="-framework OpenGL"
else
    GLFLAG="-lGL"
fi

# default argument is "sdl2", otherwise type "sdl3"
ARG="${1:-sdl2}"

VER="${ARG:3:4}"


SDLFLAG="`pkg-config --libs sdl${VER}`"
SDLCFLAGS="`pkg-config --cflags sdl${VER}`"
if [ $VER == "3" ]; then
    SDLCFLAGS="$SDLCFLAGS $SDLCFLAGS/SDL3"
fi
CFLAGS="$CFLAGS -DSDL${VER}_RENDERER $SDLCFLAGS"


CFLAGS="$CFLAGS -I../src -Wall -std=c11 -pedantic $SDLFLAG $GLFLAG -lm -O3 -g"

gcc main.c renderer.c ../src/microui.c $CFLAGS

