#!/bin/bash
set -e

export LVGL_DIR="/home/giovanni/projects/workspace-lvgl/lvgl"
export SDL2_INC="/home/giovanni/projects/workspace-mmplus/sdl2/sdl2/include"

# MI/SigmaStar libs (these you keep as-is if they live here)
export SIGMASTAR_LIB="/home/giovanni/projects/workspace-mmplus/sdl2/mini/lib"

# 👉 This dir contains libSDL2-2.0.so.0, libEGL.so, libGLESv2.so
export PREBUILT_LIB="/home/giovanni/projects/workspace-mmplus/sdl2/prebuilt/mini"

export TOOLCHAIN="miyoo-armv7.cmake"

# Use absolute files so the linker doesn't need devel symlinks
export SDL2_LIBS="${PREBUILT_LIB}/libSDL2-2.0.so.0;${PREBUILT_LIB}/libEGL.so;${PREBUILT_LIB}/libGLESv2.so"

cmake -S . -B build-miyoo \
  -DCMAKE_TOOLCHAIN_FILE="${TOOLCHAIN}" \
  -DCMAKE_BUILD_TYPE=Release \
  -DLVGL_DIR="${LVGL_DIR}" \
  -DSDL2_INCLUDE_DIRS="${SDL2_INC}" \
  -DSIGMASTAR_LIB_DIR="${SIGMASTAR_LIB}" \
  -DSDL2_LIBRARIES="${SDL2_LIBS}"

cmake --build build-miyoo -j"$(nproc)"
