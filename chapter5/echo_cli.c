#include "includes.h"

void
str_cli(FILE *fp, int sockfd)
{
  ssize_t n;
  char sendline[MAX_LINE], recvline[MAX_LINE + 1];
  
  while( (n = read(fileno(fp), sendline, MAX_LINE)) > 0 ) {
    writen(sockfd, sendline, n);
    if ( (n = read(sockfd, recvline, MAX_LINE)) > 0 ) {
      recvline[n] = 0;
      fputs(recvline, stdout);
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
