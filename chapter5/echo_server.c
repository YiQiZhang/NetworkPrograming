#include "includes.h"

void
sig_chld(int signo)
{
  pid_t pid;
  int stat;
  while( (pid = waitpid(-1, &stat, WNOHANG)) > 0 )
    printf("child %d terminated\n", pid);

  return;
}

void
str_echo(int sockfd)
{
  char buf[MAX_LINE];
  ssize_t n; 
  while( (n = Read(sockfd, buf, MAX_LINE)) > 0 ) {
    writen(sockfd, buf, n);
  }
}

int main(int argc, char **argv)
{

  if (argc < 2)
    err_sys("usage: echo_server <port>");

  int servport = atoi(argv[1]);
  int servfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t clilen;
  pid_t childpid;

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(servport);
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  servfd = Socket(AF_INET, SOCK_STREAM, 0); 
  Bind(servfd, (SA *) &servaddr, sizeof(servaddr));
  Listen(servfd, MAX_LISTEN_QUENEN);

  clilen = sizeof(cliaddr);

  Signal(SIGCHLD, sig_chld);

  while(1) {
    while((connfd = accept(servfd, (SA *) &cliaddr, &clilen)) > 0) {
      if ( (childpid = fork()) == 0 ) {
        Close(servfd);
        str_echo(connfd);
        exit(0);
      } else {
        Close(connfd);
      }
    }
  }

  return 0;
}
