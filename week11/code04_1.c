#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (){
	pid_t pid;
	
	if((pid = fork()) > 0){
		printf("[ex10_04] PPID: %d, PID:%d\n", getppid(), getpid());
		sleep (1);
	}
	else if(pid == 0){
		printf("[ex10_04] PPID: %d, PID:%d\n", getppid(), getpid());
		execl("ex10_05", "ex10_05", (char *)0);
	}
	else 
		printf ("Fail to fork\n");

	return 0;
}
