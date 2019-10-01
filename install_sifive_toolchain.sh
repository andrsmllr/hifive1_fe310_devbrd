#!/bin/bash
# Fetch official RISC-V toolchain and Open-OCD debugger from SiFive (precompiled binaries).
# Afterwards build the Freedom-E-SDK.

apt update -qq
apt install -qq -y make git gcc

RISCV_TOOLCHAIN=riscv64-unknown-elf-gcc-8.2.0-2019.05.3-x86_64-linux-ubuntu14
wget https://static.dev.sifive.com/dev-tools/${RISCV_TOOLCHAIN}.tar.gz
tar -xf ./${RISCV_TOOLCHAIN}.tar.gz
rm -f ./${RISCV_TOOLCHAIN}.tar.gz*
export RISCV_PATH=./${RISCV_TOOLCHAIN}

OPENOCD_DEBUGGER=riscv-openocd-0.10.0-2019.05.1-x86_64-linux-ubuntu14
wget https://static.dev.sifive.com/dev-tools/${OPENOCD_DEBUGGER}.tar.gz
tar -xf ./${OPENOCD_DEBUGGER}.tar.gz
rm -f ./${OPENOCD_DEBUGGER}.tar.gz*
export OPENOCD_PATH=./${OPENOCD_DEBUGGER}

cd ./freedom-e-sdk
make
