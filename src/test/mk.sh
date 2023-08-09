#!/bin/bash
riscv64-unknown-linux-gnu-gcc hwcap.c -static -O3 -s -o hwcap
riscv64-unknown-linux-gnu-as testrvv.as -march=rv64gcv -o testrvv.o
riscv64-unknown-linux-gnu-ld testrvv.o -o testrvv
