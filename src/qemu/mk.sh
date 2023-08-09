#!/bin/bash
echo '/* Generated file, do not commit */' > qemu-riscv64.h
echo 'const unsigned char QEMU_RISCV64[] = {' >> qemu-riscv64.h
# For now use the statically built qemu-8.0.3 qemu-riscv64 binary in the repo.
# This includes the fix for https://gitlab.com/qemu-project/qemu/-/issues/1793
#  which will land upstream in qemu-8.1
#xxd -i - < `which qemu-riscv64` >> qemu-riscv64.h
xxd -i - < qemu-riscv64 >> qemu-riscv64.h
echo '};' >> qemu-riscv64.h
gcc -static qemu-wrapper.c -O3 -s -o qemu-wrapper
gcc -static qemu-wrapper-embed.c -O3 -s -o qemu-wrapper-embed
