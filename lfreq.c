#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Determines proportion of each alphabet letter within a string

int main ( int argc, char* argv )
{
int list[26] = {0};
int c = getchar();
while (c != EOF )
{
	if (65 <= c <= 90)
		{list[c-65]++;}

	if (97 <= c <= 122)
		{list[c-97]++;}

c = getchar();

}

float count = 0;
for (int i = 0; i < 26; i++)
{count = count + list[i];}

for (int i = 0; i < 26; i++)
	{ if (list[i] != 0)
		{
		char l = i+97;
		float d = (list[i] / count);
 		printf("%c %.4f\n", l, d);
		 }

	}

return 0;
}

