#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>

int main ()
{
	DIR *dp;
	struct dirent *dentry;

	if ((dp = opendir (".")) == NULL)
		exit (1);

	printf ("Current Files\n");
	
while (dentry = readdir (dp))
	{
		if (dentry->d_ino != 0)
			printf ("%s\n", dentry->d_name);
	}

	rewinddir (dp);

	printf ("Deleted Files\n");

	while (dentry = readdir (dp))
	{
		if (dentry->d_ino == 0)
			printf ("%s\n", dentry->d_name);
	}

	closedir (dp);
	return 0;
}
