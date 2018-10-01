#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main ()
{
	if (chown ("test1.txt", 1000, 1000) == -1)
		exit(1);
	printf (":)");
	return 0;
}