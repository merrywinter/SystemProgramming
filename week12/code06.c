#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void timeover(int signum){
	printf("\n\nTIME OVER!!\n\n");
	exit(0);
}

int main(){
	
	char buf[1024];
	char *alpha = "matias";

	
	int timelimit;
	struct sigaction act;
	
	act.sa_handler = timeover;
	sigaction(SIGALRM, &act, NULL);

	printf("Input timelimit (sec): ");
	scanf("%d", &timelimit);

	alarm(timelimit);
	
	printf("START\n >");
	scanf("%s", buf);

	if(!strcmp (buf, alpha))
		printf(":)\n");
	else	
		printf(":(\n");
	return 0;
}

