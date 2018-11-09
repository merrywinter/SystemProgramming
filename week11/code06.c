#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	pid_t pid;
	int interval;

	if(argc != 3)
		exit(1);

	pid = atoi(argv[1]);
	interval = atoi(argv[2]);

	printf("Shell Process\n");
	printf("Process ID: %d, Group ID: %d, Session ID: %d\n", pid, getpgid(pid), getsid(pid));
	printf("Current Process\n");
	printf("Process ID: %d, Group ID: %d, Session ID: %d\n", getpid(), getpgrp(), getsid(0));
	sleep(interval);

	return 0;
}
