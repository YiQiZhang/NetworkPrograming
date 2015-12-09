#include "includes.h"

void
str_echo(int sockfd)
{
  char buf[MAXLINE];
  size_t n; 
  while( (n = readn(sockfd, buf, MAXLINE)) > 0 ) {
    writen(sockfd, buf, n);
  }
}

int main(int argc, char **argv)
{

  if (argv < 2)
    err_sys("usage: echo_server <port>");

  int servport = atoi(argv[1]);
  int servfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t clilen;
  pid_t childpid;

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_prot = htons(servport);
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  servfd = Socket(AF_INET, SOCK_STREAM, 0); 
  Bind(servfd, (SA *) &servaddr, sizeof(servaddr));
  Listen(servfd, MAX_LISTEN_QUENEN);

  clilen = sizeof(cliaddr);

  while((connfd = accept(servfd, (SA *) &cliaddr, &clilen)) < 0) {
    if ( (childpid = fork()) == 0 ) {
      Close(servfd);
      str_echo(connfd);
      exit(0);
    } else {
      Close(connfd);
    }
  }
 
  return 0;
}