#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>

#define SIZE 1024

int main(){

	struct utsname info;
	char myname[SIZE];

	uname(&info);

	printf("Node Name: %s\n", info.nodename);
	printf("System: %s\n", info.sysname);
	printf("Version: %s\n", info.version);
	printf("Machine: %s\n", info.machine);
	printf("Release: %s\n", info.release);

	gethostname(myname, SIZE);
	printf("hostname: %s\n", myname);

	return 0;
}

