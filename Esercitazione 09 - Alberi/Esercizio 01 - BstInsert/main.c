#include "tree_int.h"

Node* BstInsert(const ElemType *e, Node *n)
{
	if (IsEmptyTree(n)) {
		Node *ris = CreateRootTree(e, NULL, NULL);
		return ris;
	}

	Node *head = n;
	Node *new_foglia = CreateRootTree(e, NULL, NULL);

	while (!IsEmptyTree(n)) {
		if (n->value >= *e)
		{
			if ( n->left ==NULL) {
				n->left = new_foglia;
				break;
			}
			n = n->left;
		}
		else
		{
			if (n->right == NULL) {
				n->right = new_foglia;
				break;
			}
			n = n->right;
		}
	}
	return head;
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