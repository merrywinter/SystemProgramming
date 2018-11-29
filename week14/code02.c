#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SIZE	sizeof (struct sockaddr_in)

#define MSGSIZE 1024

int main(){

	int sockfd;
	char msg[MSGSIZE], recv[MSGSIZE];

	struct sockaddr_in client = {AF_INET,INADDR_ANY, INADDR_ANY};

	int server_len = SIZE;


	struct sockaddr_in server = {AF_INET, htons(1234)};
	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	strcpy(msg, "What's up man");

	sendto(sockfd, &msg, MSGSIZE, 0, (struct sockaddr *)&server, server_len);

	recvfrom(sockfd, &recv, MSGSIZE, 0, (struct sockaddr *)&server, &server_len);

	printf("Reply from server: %s\n", recv);

	close(sockfd);
	
	return 0;
}


