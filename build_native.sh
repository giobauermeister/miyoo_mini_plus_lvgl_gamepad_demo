#!/bin/bash

export LVGL_DIR="/home/giovanni/projects/workspace-lvgl/lvgl"

cmake -S . -B build-native \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DLVGL_DIR="${LVGL_DIR}" \
  -DSDL2_INCLUDE_DIRS="$(pkg-config --cflags-only-I sdl2 | sed 's/-I//')" \
  -DSDL2_LIBRARIES="$(pkg-config --libs sdl2)"

cmake --build build-native -j$(nproc)

# Run on PC:
# ./build-native/lvgl_gamepad_demo
