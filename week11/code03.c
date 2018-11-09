#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	pid_t pid;
	int status = 0;
	
	if((pid = fork()) > 0){
		while (!waitpid(pid, &status, WNOHANG)){
			printf("Parent: %d\n", status++);
			sleep(1);
		}
		printf("Parent: child - exit(%d)\n", status);
	}
	else if(pid == 0){
		sleep(5);
		printf("Bye!\n");
		exit(0);
	}
	else
		printf ("Fail to fork\n");

	return 0;
}
