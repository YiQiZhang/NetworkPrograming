#include _LIB_IOHELPER_H_
#define _LIB_IOHELPER_H_

#include <stdio.h>

void 
err_sys(const char *str)
{
  printf("system error: %s\n", str);
  exit(-1);
}

int
Fork(void)
{
  pid_t id;
  if ( (id = fork()) == -1)
    err_sys("fork err");

  return id;
}
#endif
