#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


void workload() {
  for (volatile int i = 0; i < 1000000; i++);
}

int main(void) {
  settickets(10);

  for (int i = 0; i < 3; i++) {
    int pid = fork();
    if (pid == 0) { // Child
      if (i == 0) settickets(30); // Process A
      else if (i == 1) settickets(20); // Process B
      else if (i == 2) settickets(10); // Process C
      workload();
      exit(0);
    }
  }

  int status;
  while (wait(&status) != -1); // Wait for all children to finish

  exit(0);
}