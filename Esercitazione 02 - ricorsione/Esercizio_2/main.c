#include <stdio.h>

int fibonacci(int n)
{
	if (n < 0)
		return -1;
	else if (n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
	int n = 8;
	int fib = fibonacci(n);
	printf("risultato: %d", fib);
	return 0;
}