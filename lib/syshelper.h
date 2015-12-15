#ifndef _LIB_SYSHELPER_H_
#define _LIB_SYSHELPER_H_

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

typedef void Sigfunc(int);

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

Sigfunc *
Signal(int signo, Sigfunc *handler)
{
  struct sigaction act, oact;

  act.sa_handler = handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  if (signo != SIGALRM) {
    act.sa_flags |= SA_RESTART;
  }

  if (sigaction(signo, &act, &oact) < 0) {
    return SIG_ERR;
  }

  return oact.sa_handler;
}
#endif
