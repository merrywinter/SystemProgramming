#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SIZE	sizeof (struct sockaddr_in)

void main ()
{
	int sockfd;
	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_port = 1234;
	addr.sin_addr.s_addr = INADDR_ANY;

	
/* ex13_02: socket open part */

	if (bind (sockfd, (struct sockaddr *) &addr, SIZE) == -1)
	{
		printf ("Bind Fail\n");
		exit(1);
	}

	close (sockfd);
}

