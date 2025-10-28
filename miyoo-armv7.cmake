set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Use the installed Miyoo toolchain under /opt
set(TOOLCHAIN_ROOT "/opt/mini")
set(TRIPLE "arm-linux-gnueabihf")

set(CMAKE_C_COMPILER   "${TOOLCHAIN_ROOT}/bin/${TRIPLE}-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_ROOT}/bin/${TRIPLE}-g++")

# Tune for Cortex-A7 hard-float
set(CMAKE_C_FLAGS_INIT "-O2 -pipe -mcpu=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard -fdata-sections -ffunction-sections")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,--gc-sections")
