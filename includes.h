#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h> /* network about */

#include "lib/sockhelper.h"
#include "lib/iohelper.h"
#include "lib/syshelper.h"

#define SA struct sockaddr 
#define MAX_LISTEN_QUENEN 1024
#define MAX_LINE 4096

#endif
