#include <stdio.h>
#include <stdlib.h>

void funzione(int n, int i, char* v, char* vcurr)
{
	if (i >= n) {
		printf("{ ");
		for (int j = 0; j < n; j++)
			printf("%c", vcurr[j]);
		printf(" }, ");
		return;
	}

	for (int a = 0; a < n; a++) {
		vcurr[i] = v[a];
		funzione(n, i + 1, v, vcurr);
	}
}

void BacktrackStr(int n)
{
	if (n <= 0 || n > 26)
		return;
	
	char v[] = { 'a','b','c','d','e','f' };
	char* vcurr = malloc(n * sizeof(char));
	funzione(n, 0, v, vcurr);
	free(vcurr);
}