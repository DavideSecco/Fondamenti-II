#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "tree_char.h"

tree funzione(char* v, int size, int i)
{
	if (i > size/2 - 1) {
		return ConsTree(&v[i], NULL, NULL);
	}

	return ConsTree(&v[i], funzione(v, size, 2 * i + 1), funzione(v, size, 2 * i + 2));
}

tree ReadTree(FILE *f)
{
	if (f == NULL)
		return EmptyTree();

	fseek(f, 0, SEEK_END);
	int size = ftell(f);

	if (size == 0)
		return EmptyTree();

	rewind(f);
	char *v = malloc(size * sizeof(char));
	
	for (int i = 0; i < size ; i++) {
		fscanf(f, "%c", &v[i]);
	}
		
	tree t = funzione(v, size, 0);
	free(v);
	return t;
}

int main()
{
	FILE *f = fopen("level_tree_3.txt", "r");
	if (f == NULL)
		return NULL;
	tree t = ReadTree(f);
	fclose(f);
	return 0;
}