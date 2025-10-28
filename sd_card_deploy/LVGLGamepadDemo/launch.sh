#!/bin/sh
set -e

# Go to this app's directory (same pattern PlayActivity uses)
SELF_DIR="$(cd -- "$(dirname "$0")" && pwd)"
cd "$SELF_DIR"

# Make sure your bundled .so files are found before system libs
export LD_LIBRARY_PATH="$SELF_DIR/lib:${LD_LIBRARY_PATH:-}"

# --- Recommended SDL defaults on Miyoo Mini Plus ---
# KMSDRM is the usual SDL2 video backend here. If you built for fbdev, switch to "fbcon".
export SDL_VIDEODRIVER="${SDL_VIDEODRIVER:-KMSDRM}"
# Alsa is the standard audio path
export SDL_AUDIODRIVER="${SDL_AUDIODRIVER:-alsa}"
# If you built with GLES2, prefer the GLES renderer; otherwise comment this out.
export SDL_RENDER_DRIVER="${SDL_RENDER_DRIVER:-opengles2}"

# Optional: keep the system from intercepting MENU while you run
# touch /tmp/disable_menu_button
# trap 'rm -f /tmp/disable_menu_button' EXIT

# Optional: log to a file for debugging (uncomment)
exec >>"$SELF_DIR/run.log" 2>&1


# Ensure the binary is executable
chmod +x ./bin/lvgl_gamepad_demo

# Run it!
exec ./bin/lvgl_gamepad_demo "$@"
