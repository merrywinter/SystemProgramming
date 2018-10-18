#include <stdio.h>
#include <unistd.h>

int main(){

	printf ("Before executing ls -l \n");
	execl ("/bin/ls", "ls", "-l", (char*)0);
	printf ("After executing ls -l \n");

	return 0;
}