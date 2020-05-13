#include <stdio.h>

int main(int argc, char *argv[])
{
	int prod = 1;
	for (size_t i = 1; i < argc; i++)
	{
		int n = atoi(argv[i]);
		prod = prod * n;
	}
	printf("prodotto: %d", prod);
	return 0;
}