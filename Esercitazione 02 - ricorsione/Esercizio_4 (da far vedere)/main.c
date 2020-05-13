#include <stdio.h>

int prodotto(int a, int b)
{
	if (a < 0 || b < 0)
		return -1;
	if (a == 0 || b == 0)
		return 0;

	if (b == 1)
		return a;
	else
		return a + prodotto(a, b - 1);
}

int main(void)
{
	int a = 2;
	int b = 1;
	int prod = prodotto(a, b);
	printf("risultato: %d", prod);
	return 0;
}