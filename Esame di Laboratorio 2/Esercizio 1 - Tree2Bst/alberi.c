#include "tree_int.h"
#include <stdlib.h>

void carica(tree t, tree* t2)
{
	if (IsEmpty(t))
		return;

	*t2 = InsertBinOrd(&t->value, *t2);

	if (IsLeaf(t))
		return;

	if (t->left != NULL)
		carica(t->left, t2);
		
	if (t->right != NULL)
		carica(t->right, t2);
}

tree Tree2Bst(tree t)
{
	tree t2 = EmptyTree();
	carica(t, &t2);
	return t2;
}