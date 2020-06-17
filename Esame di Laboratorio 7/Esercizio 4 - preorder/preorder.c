#include "tree_int.h"
#include <stdlib.h>
#include <stdio.h>

void somma(tree t, int* s)
{
	*s = *s + t->value;
	printf("%d ", t->value);

	if (IsLeaf(t))
		return;

	if (Left(t))
		somma(Left(t), s);

	if (Right(t))
		somma(Right(t), s);

}

extern int PreOrder(tree t)
{
	if (IsEmpty(t))
		return 0;

	int s = 0;
	somma(t, &s);
	
	return s;
}