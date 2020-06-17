#include "tree_int.h"

extern Node* BstInsert(const ElemType *e, Node *n)
{
	if (IsEmptyTree(n))
		return CreateRootTree(e, NULL, NULL);;

	if (ElemCompare(&n->value, e) >= 0)
		n->left = BstInsert(e, n->left);
	else
		n->right = BstInsert(e, n->right);

	return n;
}
int main()
{
	Node *ris = NULL;
	const ElemType v[] = { 12 , 4 , 21 , 0, 5, 18, 77, 2, 8, 6, 9 };
	int size = sizeof(v) / sizeof(ElemType);
	int i = 0;

	while (i < size)
	{
		ris = BstInsert(&v[i], ris);
		i++;
	}
}