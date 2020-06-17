#include "tree_expr.h"
#include <stdlib.h>
#include <stdio.h>

// NON E' PERFETTO
// hai dovuto mettere una funzione aggiuntiva perchè mancava un '('...

void aux(tree t)
{
	if (IsLeaf(t)) {
		printf("%d", t->value.vl);
		return;
	}

	if ((Left(t) != NULL))
		aux(t->left);

	printf(" %c ", t->value.op);

	// caso "metti parentesi '('
	if (!IsLeaf(t->left) || !IsLeaf(t->right))
		printf("(");

	if ((Right(t) != NULL))
		aux(t->right);

	printf(")");
}

void ExpressionTree(tree t)
{
	if (IsEmpty(t))
		return;

	printf("(");
	aux(t);
}

