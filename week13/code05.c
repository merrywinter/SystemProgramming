#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SIZE	sizeof (struct sockaddr_in)

int main(){
	
	int sockfd_listen, sockfd_connect;
	char c;
	struct sockaddr_in server = {AF_INET, 1234, INADDR_ANY};

	/* ex13_02: socket open part */
	
	/* ex13_03: socket bind part */	
	
	/* ex13_04: socket listen part */
	
	while(1){
		if((sockfd_connect = accept(sockfd_listen, NULL, NULL)) == -1){
			printf ("Accept fail\n");
			continue;
		}
	}

	return 0;
}

