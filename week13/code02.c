#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(){
	
	int sockfd;
	
	if((sockfd = socket (AF_INET, SOCK_STREAM, 0)) == -1){
		printf ("Socket Open Fail\n");
		exit(1);
	}

	printf("Socket descriptor: %d\n", sockfd);

	close(sockfd);
	
	return 0;
}

