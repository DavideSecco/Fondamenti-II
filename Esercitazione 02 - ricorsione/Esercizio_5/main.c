#include <stdio.h>

unsigned long long fattoriale(int n)
{
	if (n < 0)
		return 0;

	if (n == 1 || n == 0)
		return 1;
	else
		return n * fattoriale(n - 1);
}

int main(void)
{
	int n = 2;
	unsigned long long fatt = fattoriale(n);
	printf("fatt: %llu", fatt);
	return 0;
}