#ifndef _LIB_SOCKHELPER_H_
#define _LIB_SOCKHELPER_H_

#include <sys/socket.h>
#include "syshelper.h"

int
Socket(int family, int type, int protocol)
{
  int sockfd;

  if ((sockfd = socket(family, type, protocol)) < 0)
    err_sys("socket err");

  return sockfd;
}

void
Bind(int sockfd, const struct sockaddr *sa, socklen_t len)
{
  if (bind(sockfd, sa, len) < 0)
    err_sys("bind err"); 
} 

void
Listen(int sockfd, int backlog)
{
  if (listen(sockfd, backlog) < 0)
    err_sys("listen err");
}

int
Connect(int sockfd, const struct sockaddr *sa, socklen_t len)
{
  int status;
  if ( (status = connect(sockfd, sa, len)) < 0)
    err_sys("connect err");

  return status;
}

void
Shutdown(int sockfd, int howto)
{
  if ( shutdown(sockfd, howto) < 0 )
    err_sys("shutdown err");
}

void
Close(int fd)
{
  if (close(fd) == -1)
    err_sys("close err");
}

#endif
