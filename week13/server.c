#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>

#define SIZE	sizeof (struct sockaddr_in)

void closesock (int sig);

int sockfd_connect;

void main ()
{
	int sockfd_listen;
	char c;
	struct sockaddr_in server = {AF_INET, 1234, INADDR_ANY};
	struct sigaction act;

	act.sa_handler = closesock;
	sigfillset (&(act.sa_mask));
	sigaction (SIGPIPE, &act, NULL);

	/* ex13_02: socket open part */
	if ((sockfd_listen = socket (AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf ("Socket Open Fail\n");
		exit(1);
	}
	/* ex13_03: socket bind part */
	if (bind (sockfd_listen, (struct sockaddr *) &server, SIZE) == -1)
	{
		printf ("Bind Fail\n");
		exit(1);
	}
	/* ex13_04: socket listen part */
	if (listen (sockfd_listen, 5) == -1)
	{
		printf ("listen fail\n");
		exit(1);
	}
	while (1)
	{
		/* ex13_05: socket connect part */
		if ((sockfd_connect = accept (sockfd_listen, NULL, NULL)) == -1)
		{
			printf ("Accept fail\n");
			continue;
		}
		
		printf ("Request Accepted\n");

		while (recv (sockfd_connect, &c, 1, 0) > 0)
		{
			printf ("%c received\n", c);
			send (sockfd_connect, &c, 1, 0);
			
		}
		
		printf ("sockfd_connect closed\n");
		close (sockfd_connect);
	}
}

void closesock (int sig)
{
	close (sockfd_connect);
	printf ("connection lost\n");
	exit (1);
}

