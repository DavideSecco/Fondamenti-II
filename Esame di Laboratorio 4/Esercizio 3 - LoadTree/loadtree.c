#include "tree_char.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// C'è memory leak da qualche parte... (funziona in tutti i casi però)

tree Back(char *v, int size, int* pos)
{
	if (*pos >= size)
		return NULL;

	if (v[*pos] == '.') {
		*pos = *pos + 1;
		return ConsTree(&v[*pos], NULL, NULL);
	}
	else
	{
		tree t = malloc(sizeof(node));
		t->value = v[*pos];
		*pos = *pos + 1;
		t->left = Back(v, size, pos);
		*pos = *pos + 1;
		t->right = Back(v, size, pos);
		return t;
	}
}

tree LoadTree(const char* filename)
{
	tree t = EmptyTree();
	FILE* f = fopen(filename, "r");
	
	if (f == NULL)
		return t;
	
	char *v = NULL;
	int size = 0;
	while (1)
	{
		char x;
		int ris = fscanf(f, "%c", &x);
		if (ris != 1)
			break;
		if ((x >= 97 && x < 123) || x == '.' || (x>=48 && x<= 48+10)) {
			size++;
			v = realloc(v, size * sizeof(char));
			v[size - 1] = x;
		}
	}

	int pos = 0;
	t = Back(v, size, &pos);
	return t;
}

int main()
{
	tree t = LoadTree("albero6.txt");
	return 0;
}

