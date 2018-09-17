#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int filedes;
	char tmpstr[] = "Hello my friend!!\n";
	filedes = open ("ex3_text.txt", O_RDWR|O_CREAT, 0644);
	write (filedes, tmpstr, strlen(tmpstr));

	close(filedes);
	
	return 0;
}

