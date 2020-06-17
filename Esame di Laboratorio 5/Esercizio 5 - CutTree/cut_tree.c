#include "tree_int.h"
#include <stdlib.h>

// NON è COMPLETO --> non sai eliminare i nodi in fondo

tree CutTree(tree t, int cut_value)
{
	if (IsEmpty(t))
		return NULL;

	if (t->value == cut_value) {
		free(t);
		return NULL;
	}

	if (IsLeaf(t))
		return t;

	return ConsTree(&t->value, CutTree(Left(t), cut_value), CutTree(Right(t), cut_value));
}