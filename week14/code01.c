#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SIZE	sizeof (struct sockaddr_in)

#define MSGSIZE 1024

int main(){

	int sockfd;
	char msg[MSGSIZE];

	struct sockaddr_in server = {AF_INET, htons(1234), INADDR_ANY};

	struct sockaddr_in client;
	int client_len = SIZE;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	bind(sockfd, (struct sockaddr*)&server, SIZE);

	recvfrom(sockfd, &msg, MSGSIZE, 0, (struct sockaddr*)&client, &client_len);

	printf("Received from client: %s\n", msg);

	sendto(sockfd, &msg, MSGSIZE, 0, (struct sockaddr*)&client, client_len);
	close(sockfd);
	
	return 0;
}

