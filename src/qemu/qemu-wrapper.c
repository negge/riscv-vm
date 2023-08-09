/*
 * Pass arguments to qemu binary
 */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
  char *newargv[argc + 3];

  newargv[0] = argv[0];
  newargv[1] = "-cpu";
  newargv[2] = "rv64,v=true,vext_spec=v1.0";

  memcpy(&newargv[3], &argv[1], sizeof(*argv) * (argc -1));
  newargv[argc + 2] = NULL;
  return execve("/usr/bin/qemu-riscv64", newargv, envp);
}
