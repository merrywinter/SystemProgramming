#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("[ex10_05] PPID: %d, PID:%d\n", getppid(), getpid());

	return 0;
}