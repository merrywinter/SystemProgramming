#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
	struct stat finfo;
	char fname[1024];

	memset (fname, 0, sizeof (fname));

	if (argc > 1)
		strcpy (fname, argv[1]);
	else
		strcpy (fname, argv[0]);

	if (stat(fname, &finfo) == -1)
	{
		fprintf (stderr, ":X %s \n", fname);
		exit(1);
	}

	printf ("%s \n", fname);
	printf ("ID: %d \n", (int)finfo.st_dev);
	printf ("Inode number: %d \n", (int)finfo.st_ino);
	printf ("File mode: %d \n", finfo.st_mode);
	printf ("Number of links: %d \n", finfo.st_nlink);
	printf ("User ID: %d \n", finfo.st_uid);
	printf ("Group ID: %d \n", finfo.st_gid);
	printf ("File Size: %d \n", (int)finfo.st_size);
	printf ("Last access time: %u \n", finfo.st_atim);
	printf ("Last modify time: %u \n", finfo.st_mtim);
	printf ("Last stat time: %u \n", finfo.st_ctim);
	printf ("I/O Block Size: %d \n", (int)finfo.st_blksize);
	printf ("Number of blocks: %d \n", (int)finfo.st_blocks);
	
	return 0;
}
