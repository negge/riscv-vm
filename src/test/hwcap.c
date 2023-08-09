#include <sys/auxv.h>
#include <stdio.h>

#define ISA_V_HWCAP (1 << ('v' - 'a'))

void main() {
  unsigned long hw_cap = getauxval(AT_HWCAP);
  printf("RVV %s\n", hw_cap & ISA_V_HWCAP ? "detected" : "not found");
}
