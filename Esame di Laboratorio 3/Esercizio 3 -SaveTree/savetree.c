#include "tree_int.h"
#include <stdio.h>

void Stampa(tree t, FILE *f)
{
	if (IsEmpty(t))
		return;

	if (IsLeaf(t)) {
		fprintf(f, "%d ", t->value);
		return;
	}

	fprintf(f, "%d ", t->value);

	if (!IsEmpty(Left(t))) {
		Stampa(Left(t), f);
	}

	if (!IsEmpty(Right(t))) {
		Stampa(Right(t), f);
	}
}

bool SaveTree(tree t, const char *filename)
{
	FILE *f = fopen(filename, "w");

	if (f == NULL)
		return false;

	Stampa(t, f);
	fclose(f);
	return true;
}