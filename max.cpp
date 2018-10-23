#include <iostream>

using namespace std;

int Max(int A[], int start, int end) {

	int max = A[start];

	if (start == end) { return max; }

	if ( A[start] < A[end] ) { return Max(A, (start+1), end); }

	else return Max(A, start, (end-1));

}


int Pow(int base, int exp)	{

	if (exp == 0) { return 1; }

	return base*(Pow(base, exp-1));

}

int LFib(int n)		{
	if (n == 1) { return (n,0); }
	if (n == 0) {return (n,0); }
	int (i,j) = LFib(n-1);
	return (i+j,i);

}


int main (void) {

int Array[] = {40,2,10,300,50};

cout << Max(Array, 0, 4) << endl;

cout << Pow(10,3) << endl;

cout << LFib(5) << endl;

return 0;

}

