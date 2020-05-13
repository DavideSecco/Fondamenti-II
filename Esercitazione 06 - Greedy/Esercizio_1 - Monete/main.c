#include <stdlib.h>
#include <stdio.h>

extern int* Monete(int *t, int size, int b);

void stampa(int *v, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", v[i]);
	}
}

int main()
{
	int t[] = { 50, 20, 10, 5, 2, 1 };
	int size = sizeof(t) / sizeof(int);
	int b = 0;
	int	*v = Monete(t, size, b);
	printf("Monete:   ");
	stampa(t, size);
	printf("\nPrendile: ");
	stampa(v, size);
	return 0;
}