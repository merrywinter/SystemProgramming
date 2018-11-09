#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	pid_t pid;

	if((pid = fork()) > 0){
		sleep (1);
		exit (1);
	}
	else if(pid == 0){
		printf ("Old Session ID: %d\n", getsid(0));
		printf ("New Session ID: %d\n", setsid());
		sleep(600);
	}

	return 0;
}
