#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]){
	
	struct hostent *hent;
	in_addr_t ipaddr;
	char **ptr;

	if(argc < 2){
		printf("%s ip_address\n", argv[0]);
		exit(1);
	}

	if((ipaddr = inet_addr(argv[1])) == -1){
		printf(":(((\n");
		exit(1);
	}

	if((hent = gethostbyaddr((char *)&ipaddr, 4, AF_INET)) == NULL){
		printf(":(((((\n");
		exit(1);
	}

	printf("Official name: %s\n", hent->h_name);

	for(ptr = hent->h_aliases; *ptr != NULL; *ptr++)
		printf("\talias: %s\n", *ptr);

	if(hent->h_addrtype == AF_INET){
		ptr = hent->h_addr_list;
		
		while(*ptr != NULL){
			printf("\taddress: %s\n", inet_ntoa (*((struct in_addr *)*ptr)));
			*ptr++;
		}
	}

	return 0;
}

