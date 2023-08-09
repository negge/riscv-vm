/*
 * Pass arguments to qemu binary
 */

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

#include "qemu-riscv64.h"

int main(int argc, char **argv, char **envp) {
  char *newargv[argc + 3];

  newargv[0] = argv[0];
  newargv[1] = "-cpu";
  newargv[2] = "rv64,v=true,vext_spec=v1.0";

  memcpy(&newargv[3], &argv[1], sizeof(*argv) * (argc -1));
  newargv[argc + 2] = NULL;

  int fd = memfd_create("qemu-riscv64", MFD_CLOEXEC);
  if (fd == -1) {
    perror("memfd_create");
    return 1;
  }

  if (write(fd, QEMU_RISCV64, sizeof(QEMU_RISCV64)) != sizeof(QEMU_RISCV64)) {
    perror("write");
    return 2;
  }

  return fexecve(fd, newargv, envp);
}
