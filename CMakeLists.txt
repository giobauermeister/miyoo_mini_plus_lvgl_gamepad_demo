cmake_minimum_required(VERSION 3.16)
project(lvgl_gamepad_demo C)
set(CMAKE_C_STANDARD 99)

# --- LVGL repo on your machine ---
set(LVGL_DIR "${CMAKE_SOURCE_DIR}/lvgl" CACHE PATH "Path to local LVGL")
if(NOT EXISTS "${LVGL_DIR}/CMakeLists.txt")
  message(FATAL_ERROR "LVGL not found at ${LVGL_DIR}")
endif()

# --- SDL headers from your Miyoo SDL2 port ---
set(SDL2_INCLUDE_DIRS "/home/giovanni/projects/workspace-mmplus/sdl2/sdl2/include")

# Detect header layout (flat vs nested)
if(EXISTS "${SDL2_INCLUDE_DIRS}/SDL.h")
  set(_LV_SDL_INCLUDE "<SDL.h>")
  set(_SDL_EXTRA_INC "")
elseif(EXISTS "${SDL2_INCLUDE_DIRS}/SDL2/SDL.h")
  set(_LV_SDL_INCLUDE "<SDL2/SDL.h>")
  set(_SDL_EXTRA_INC "${SDL2_INCLUDE_DIRS}/SDL2")
else()
  message(FATAL_ERROR "Can't find SDL.h under ${SDL2_INCLUDE_DIRS} (flat or SDL2/).")
endif()

message(STATUS "SDL include root: ${SDL2_INCLUDE_DIRS}")
message(STATUS "LV_SDL_INCLUDE_PATH = ${_LV_SDL_INCLUDE}")

# ---- Make these GLOBAL so LVGL sees them while building its SDL driver ----
# (must be BEFORE add_subdirectory)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}   # so LV_CONF_INCLUDE_SIMPLE finds lv_conf.h
  ${SDL2_INCLUDE_DIRS}
  ${_SDL_EXTRA_INC}
)
add_compile_definitions(
  LV_CONF_INCLUDE_SIMPLE=1
  LV_SDL_INCLUDE_PATH=${_LV_SDL_INCLUDE}
)

# --- Where the SigmaStar 'mini' libs live in your repo ---
set(SIGMASTAR_LIB_DIR "/home/giovanni/projects/workspace-mmplus/sdl2/mini/lib")

# --- Give LVGL a unique sub-build dir to avoid collisions ---
string(MD5 LVGL_DIR_HASH "${LVGL_DIR}")
set(LVGL_BUILD_DIR "${CMAKE_BINARY_DIR}/_lvgl_build_${LVGL_DIR_HASH}")

# ---- Pull in LVGL (creates target 'lvgl') ----
add_subdirectory(${LVGL_DIR} ${LVGL_BUILD_DIR})

add_subdirectory(gamepad_ui)

# ---- Your app ----
add_executable(lvgl_gamepad_demo
  src/main.c
)

target_include_directories(lvgl_gamepad_demo PRIVATE
  ${SDL2_INCLUDE_DIRS}
  ${_SDL_EXTRA_INC}
  ${LVGL_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Help the cross-linker resolve transitive deps of libSDL2 at link time
# (points it at the SigmaStar libs that SDL2 needs)
target_link_options(lvgl_gamepad_demo PRIVATE
  -Wl,-rpath-link,${SIGMASTAR_LIB_DIR}
)

# IMPORTANT: link SDL/EGL/GLES (passed via -DSDL2_LIBRARIES=...) and SigmaStar MI libs
target_link_libraries(lvgl_gamepad_demo PRIVATE
  ${SDL2_LIBRARIES}
  lvgl
  lib-ui
  m dl pthread
  ${SIGMASTAR_LIB_DIR}/libmi_ao.so
  ${SIGMASTAR_LIB_DIR}/libmi_common.so
  ${SIGMASTAR_LIB_DIR}/libmi_sys.so
  ${SIGMASTAR_LIB_DIR}/libmi_gfx.so
  ${SIGMASTAR_LIB_DIR}/libshmvar.so
  ${SIGMASTAR_LIB_DIR}/libssgfx.so
)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(lvgl_gamepad_demo PRIVATE -Wall -Wextra -Wno-unused-parameter)
endif()

# Let the binary load .so from ./lib at runtime (on
