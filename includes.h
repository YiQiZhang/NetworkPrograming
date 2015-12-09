#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/socket.h> /* network about */
#include <netinet/in.h> /* sockaddr_in */
#include <arpa/inet.h> /* inet_aton, inet_addr, inet_ntoa */

#include "lib/sockhelper.h"
#include "lib/iohepler.h"
#include "lib/syshelper.h"

#define SA struct sockaddr 
#define MAX_LISTEN_QUENEN 1024
#define MAX_LINE 4096

#endif
