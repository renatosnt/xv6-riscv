#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int
main(int argc, char *argv[])
{
  int ret = settickets(10);
  fprintf(1, "settickets retornou %d\n", ret);

  exit(0);
}