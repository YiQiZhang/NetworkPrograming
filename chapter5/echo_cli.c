#include "includes.h"

void
str_cli(FILE *fp, int sockfd)
{
  ssize_t rn, wn;
  char sendline[MAX_LINE], recvline[MAX_LINE + 1];
  
//  while( (rn = readn(fileno(fp), sendline, MAX_LINE)) > 0) {
//    sendline[rn] = EOF;
//    if ( ( wn = writen(sockfd, sendline, rn) ) == rn) {
//      while ( (rn = readn(sockfd, recvline, MAX_LINE)) > 0) {
//        writen(fileno(stdout), recvline, rn);
//      }
//    } else {
//      err_sys("str_cli error");
//    }
//  }

  sendline[0] = 'a';
  sendline[1] = 'b';
  sendline[2] = 0;

  if ( (wn = writen(sockfd, sendline, 3)) == 3 ) {
    if ( (rn = readn(sockfd, recvline, MAX_LINE)) > 0 ) {
      writen(fileno(stdout), recvline, rn);
    }
  }
}


int
main(int argc, char **argv)
{
  if (argc < 3)
    err_sys("usage: echo_client <ip> <port>");

  int connfd;
  struct sockaddr_in servaddr;

  connfd = Socket(AF_INET, SOCK_STREAM, 0);
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(atoi(argv[2]));

  Connect(connfd, (SA *)&servaddr, sizeof(servaddr));

  str_cli(stdin, connfd);

  return 0;
}
