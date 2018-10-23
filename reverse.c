#include <stdio.h>
#include <math.h>

//reverses an array

void reverse ( int arr[], unsigned int len)

{
int i = 0;
	while (i < floor(len/2) )
	{
		int b = arr[i];
		arr[i] = arr[len-1-i];
		arr[len-1-i] = b;
		i++;
	}

}

