#include <stdio.h>
#include <unistd.h>

int main(){

	char *arg[] = {"ls", "-l", (char*)0};
	printf("Before executing ls -l \n");
	execv("/bin/ls", arg);
	printf("After executing ls -l \n");

	return 0;
}
