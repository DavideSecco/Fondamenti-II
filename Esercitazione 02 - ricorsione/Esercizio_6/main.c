#include <stdio.h>

int divisione(int a, int b)
{
	if (a <= 0 || b <= 0)
		return -1;

	if (a == b)
		return 1;
	else
		return divisione(a - b, b) + 1;
}

int main()
{
	int a = 3;
	int b = 1;
	int ris = divisione(a, b);
	printf("%d : %d =  %d", a, b, ris);
	return 0;
}