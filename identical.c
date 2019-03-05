#include <stdio.h>

//between 2 arrays: return 1 if they are identical, 0 if they are not.
//Code developed by me for an assignment from CMPT 127, Simon Fraser University, Summer 2018

int identical ( int a[], int b[], unsigned int len )
{
	unsigned int is_indent = 1;
	for (unsigned int i = 0; i < len; i++)
	{
		if (a[i] != b[i])

		{
			is_indent = 0;

 		}

	}

	return is_indent;
}

