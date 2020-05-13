#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	char filename[] = "test.txt";

	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		fprintf(stderr, "Non e' stato possibile aprire il file.");
		return EXIT_FAILURE;
	}

	char s[100]; // 99 caratteri + 0
	printf("Inserire stringa:");
	scanf("%s", s);

	char p[100]; // 99 caratteri + 0
	size_t cnt = 0;
	while (1) {
		// Provo a leggere un elemento dal file
		int r = fscanf(f, "%s", p);
		// Verifico che la lettura sia andata a buon fine
		if (r != 1) {
			break;
		}
		// Uso l'elemento che ho appena letto
		if (strcmp(s, p) == 0) {
			cnt++;
		}
	}

	printf("%d", cnt);

	fclose(f);

	return EXIT_SUCCESS;
}