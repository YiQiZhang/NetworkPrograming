#ifndef _LIB_IOHELPER_H_
#define _LIB_IOHELPER_H_

#include "syshelper.h"

int
readn(int sockfd, char *buf, size_t len)
{
  size_t nleft, nread;
  char *ptr = buf;

  nleft = len;

  while (nleft > 0) {
    if ((n = read(sockfd, buf, nleft) > 0) {
    }
    nleft -= n;
  }

}
#endif
