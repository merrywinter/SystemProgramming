#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SIZE	sizeof (struct sockaddr_in)

void main ()
{
	int sockfd_listen;
	char c;
	struct sockaddr_in server = {AF_INET, 1234, INADDR_ANY};

	/* ex13_02: socket open part */
	
	/* ex13_03: socket bind part */
	
	if (listen (sockfd_listen, 5) == -1)
	{
		printf ("listen fail\n");
		exit(1);
	}

	close (sockfd_listen);
	
}

