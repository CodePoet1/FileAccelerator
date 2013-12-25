/********************************************************************
 * TonyO                                                            *
 * 25/12/2013                                                       *
 *                                                                  * 
 *
 *                                                                  * 
 ********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


#define oops(m,x) {perror(m);exit(x);}

int make_dgram_client_socket();
int make_internet_address(char *, int, struct sockaddr_in *);

int main(int ac, char *av[])
{
  int sock;
  char *msg;
  struct sockaddr_in saddr;
  int n;

  if(ac != 4){
    fprintf(stderr, "Usage: dgsend host port 'message'\n");
    exit(1);
  }
  msg=av[3];

  if((sock = make_dgram_client_socket()) == -1)
    oops("cannot make socket",2);

  make_internet_address(av[1], atoi(av[2]), &saddr);

  for(n=0;n<10;n++){
    if ( sendto(sock, msg, strlen(msg), 0, (struct sockaddr *)&saddr, sizeof(saddr)) == -1)
      oops("sendto failed", 3);
  }
  return 0;
}
