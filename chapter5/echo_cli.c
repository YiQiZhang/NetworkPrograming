#include "includes.h"

void
str_cli(FILE *fp, int sockfd)
{
  ssize_t rn, wn;
  char buf[MAX_LINE];
  
  while( (rn = readn(fileno(fp), buf, MAX_LINE)) > 0) {
    printf("cli read %d bytes from stdio\n", (int) rn);
    if ( ( wn = writen(sockfd, buf, rn) ) == rn) {
      printf("cli write %d bytes to sockfd\n", (int) wn);
      while ( (rn = readn(sockfd, buf, MAX_LINE)) > 0) {
        printf("cli read %d bytes from sockfd\n", (int) rn);
        writen(fileno(stdout), buf, rn);
      }
    } else {
      err_sys("str_cli error");
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
