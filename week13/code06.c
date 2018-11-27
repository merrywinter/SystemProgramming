#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE	sizeof (struct sockaddr_in)

int main(){

	int sockfd;
	char send_c, recv_c;
	struct sockaddr_in server ={AF_INET, 1234};

	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	/* ex13_02: socket open part */ 
	
	/* ex13_03: socket bind part */

	/* ex13_04: socket listen part */

	/* ex13_05: socket accept part */

	if((connect(sockfd, (struct sockaddr *)&server, SIZE)) == -1){
		printf("Connet fail\n");
		exit(1);
	}

	close(sockfd);
}

