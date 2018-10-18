#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;

	printf ("Hello!\n");

	pid = fork();

	if(pid > 0){
		printf ("Parent\n");
		sleep (1);
	}
	else if(pid == 0){
		printf ("Child\n");
		execl ("/bin/ls", "ls", "-l", (char*)0);
		printf ("ls Fail!!\n");
	}
	else
		printf ("Parent: Fork Fail T_T \n");
	printf ("Bye!\n");

	return 0;
}