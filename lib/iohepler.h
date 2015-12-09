#ifndef _LIB_IOHELPER_H_
#define _LIB_IOHELPER_H_

#include "syshelper.h"

ssize_t
readn(int sockfd, char *buf, size_t len)
{
  size_t nleft;
  ssize_t n;
  char *ptr = buf;

  nleft = len;

  while (nleft > 0) {
    if ((n = read(sockfd, ptr, nleft)) < 0) {
      if (errno == EINTR)
        continue;
	
      return -1;
    } else if ( n == 0 ) {
      break;
    }
    nleft -= n;
    ptr += n;
  }

  return len - nleft; 
}

ssize_t
writen(int sockfd, char *buf, size_t len)
{
  ssize_t n;
  size_t nleft;
  char * ptr;

  nleft = len;
  ptr = buf;

  while (nleft > 0) {
    if ( (n = write(sockfd, ptr, nleft)) < 0) {
      if (errno == EINTR)
        continue;
      else 
	return -1;
    } else if ( n == 0 ) {
      return -1;
    }

    nleft -= n;
    ptr += n;
  }

  return n;
} 

#endif
