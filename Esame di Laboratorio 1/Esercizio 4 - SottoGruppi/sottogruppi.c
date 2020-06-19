#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//E' approssimativo... Non controlla bene che ci siano gruppi che non hanno persone con la prima lettera uguale o consecutiva

void Back(char **v, int size, int i, int k, char** vcurr, int* nsol)
{
	if (i == k) {
		// Controllo se hanno la prima lettera uguale
		if ((k > 1 && (vcurr[0][0] - vcurr[1][0]) == 0) || (k > 1 && abs(vcurr[0][0] - vcurr[1][0]) == 1))
			return;
		*nsol = *nsol + 1;
		// stampo
		printf("{");
		for (int j = 0; j < k; j++) {
			printf(" %s", vcurr[j]);
			if (j + 1 != k)
				printf(",");
		}
		printf(" }\n");
		return;
	}

	for (int a = 0; a < size; a++) {
		if (i == 0 || strcmp(vcurr[i - 1], v[a]) != 0) {
			strcpy(vcurr[i], v[a]);
			Back(v, size, i + 1, k, vcurr, nsol);
		}		
	}
}

int Sottogruppi(const char* filename, int k)
{
	if (k == 0)
		return -1;

	FILE *f = fopen(filename, "r");
	if (f == NULL)
		return -1;
	
	int size = 0;
	while (1)
	{
		char c;
		int ris = fscanf(f, "%c", &c);
		if (ris != 1)
			break;
		if (c == '\n')
			size++;
	}

	fseek(f, 0, SEEK_SET);
	char **v = malloc(size * sizeof(char*));
	
	for(int i = 0; i<size; i++)	{
		char s[20];
		int ris = fscanf(f, "%s", s);
		if (ris != 1)
			break;
		v[i] = malloc(20 * sizeof(char));
		strcpy(v[i], s);
	}
	
	char **vcurr = malloc(k * sizeof(char*));
	for (int i = 0; i < k; i++) {
		vcurr[i] = malloc(20 * sizeof(char));
	}
	int nsol = 0;
	Back(v, size, 0, k, vcurr, &nsol);
	fclose(f);
	return nsol;
}

int main()
{
	int n = Sottogruppi("es4_input1.txt", 1);
	return 0;
}