#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main ()
{
	char *fname = "test.txt";
	//char *fname = "test1.txt";

	if (access (fname, R_OK) == -1)
	{
		fprintf (stderr, "User cannot read file %s\n",fname);
		exit (1);
	}
	printf ("%s readable, proceeding\n", fname);
	return 0;
}