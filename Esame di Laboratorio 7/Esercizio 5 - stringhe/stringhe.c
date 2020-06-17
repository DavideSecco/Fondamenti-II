#include <stdio.h>
#include <stdlib.h>

void stampa(char *v, int size)
{
	printf("{ ");
	for (int i = 0; i < size; i++) { 
		printf("%c", v[i]);
	}
	printf(" }, ");
}

void back(int n, char *v, int i, char* vcurr)
{
	if (i == n) {
		stampa(vcurr, n);
		return;
	}

	for (int a = 0; a < n; a++)
	{
		vcurr[i] = v[a];
		back(n, v, i + 1, vcurr);
	}
}

void BacktrackStr(int n)
{
	if (n <= 0 || n > 26)
		return;

	char v[] = { 'a', 'b', 'c', 'd' };
	char* vcurr = malloc(n * sizeof(char));
	back(n, v, 0, vcurr);
	free(vcurr);
}