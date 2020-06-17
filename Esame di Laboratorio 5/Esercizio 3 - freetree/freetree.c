#include "tree_int.h"
#include <stdio.h>
#include <stdlib.h>

// c'è memory leak

void FreeTree(tree t)
{
	if (IsEmpty(t))
		return;
	
	if (IsLeaf(t)) {
		printf("{%d}, ", t->value);
		return;
	}

	printf("{%d}, ", t->value);

	if (!IsEmpty(Left(t))) {
		FreeTree(Left(t));
		free(Left(t));
	}

	
	if (!IsEmpty(Right(t))) {
		FreeTree(Right(t));
		free(Right(t));
	}
	
	return;
}