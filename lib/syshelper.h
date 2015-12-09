#ifndef _LIB_SYSHELPER_H_
#define _LIB_SYSHELPER_H_

#include <stdio.h>
#include <unistd.h>

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
