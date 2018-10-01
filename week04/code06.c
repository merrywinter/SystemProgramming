#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main ()
{
	char buf[255];
	int nread;
	
	memset (buf, 0, sizeof(buf));

	nread = readlink ("soft1.txt", buf, 255);
	write(1, buf, nread);
	printf ("\n");
	return 0;
}