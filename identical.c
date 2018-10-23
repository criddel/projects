#include <stdio.h>

//between 2 arrays: return 1 if they are identical, 0 if they are not.

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

