#include <stdint.h>
#include <stdio.h>

int f(int n) {

	if ((n == 0) || (n == 1)) { return (1, 0); }
	else {
		return (f(n-1) + f(n-2));
	}

}

int main ()	{

printf("%d\n", f(100));

return 0;

}
