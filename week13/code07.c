#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE	sizeof (struct sockaddr_in)
int sockfd_connect;

void main ()
{
	int sockfd_listen, sockfd_connect;
	char c;
	struct sockaddr_in server = {AF_INET, 1234, INADDR_ANY};

	/* ex13_02: socket open part */
	
	/* ex13_03: socket bind part */
	
	/* ex13_04: socket listen part */
	
while (1)
	{
		/* ex13_05: socket connect part */
		
		while (recv (sockfd_connect, &c, 1, 0) > 0)
			send (sockfd_connect, &c, 1, 0);
		
		close (sockfd_connect);
	}
}

