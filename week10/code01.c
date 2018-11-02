#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

	pid_t pid;
	int i = 0;

	i++;

	printf ("Before Calling fork (%d)\n", i);

	pid = fork ();

	if(pid == 0){
		printf ("Child Process (%d)\n", ++i);
	}
	else if (pid > 0){
		printf ("Parent Process (%d)\n", --i);
	}
	else
		printf ("Fork Fali\n");
	
	return 0;
}
