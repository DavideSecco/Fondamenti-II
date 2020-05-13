#include <stdio.h>

int somma(int n)
{
	if (n <= 0)
		return -1;
	
	if (n == 1)
		return 1;
	else
		return somma(n - 1) + n;
}

int main(void)
{
	int n = 4;
	int s = somma(n);
	printf("somma: %d", s);
	return 0;
}