#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main ()
{
	int filedes;
	mode_t oldmask;

	filedes = open ("test1.txt", O_CREAT, 0777);
	close (filedes);

	oldmask = umask (037);	
	filedes = open ("test2.txt", O_CREAT, 0777);
	close (filedes);
	return 0;
}