#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum){
	printf("\nSIGINT cought\n\n");
}

int main(){
	struct sigaction act;
	
	sigfillset(&(act.sa_mask));
	act.sa_handler = handler;
	sigaction(SIGINT, &act, NULL);

	printf("Pause Return %d\n", pause());
	
	return 0;
}

