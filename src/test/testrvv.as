.global _start

_start:
  vsetvli t0, a2, e32
  addi a0, x0, 0
  addi a7, x0, 93
  ecall
