#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){

	pid_t pid;
	int status;

	pid = fork();

	if (pid > 0){ // Parent Process
		printf ("Parent: waiting ...\n");
		wait(&status);
	}
	else if(pid == 0){ // Child Process
		sleep(1);
		printf("Child: bye!\n");
		exit(1234);
	}
	else
		printf ("Fail to fork\n");

	printf ("QQ!\n");

	return 0;
}