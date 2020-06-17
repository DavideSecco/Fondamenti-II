#include "tree_int.h"

//Da controllare: il programma controlla solo le foglie?

void funzione(const Node *n, ElemType *max)
{
	if (IsLeafTree(n)) {
		if (max == NULL || *max < n->value)
			*max = n->value;
		return;
	}

	if (n->left != NULL) {
		funzione (n->left, max);
	}
	if (n->right != NULL) {
		funzione(n->right, max);
	}
	
	return;
}

const ElemType* TreeMax(const Node *n)
{
	if (n == NULL)
		return NULL;

	ElemType max = 0;

	funzione(n, &max);

	return &max;
}

Node* BstInsert(const ElemType *e, Node *n)
{
	if (IsEmptyTree(n))
	{
		Node *ris = CreateRootTree(e, NULL, NULL);
		return ris;
	}

	Node *head = n;
	Node *new_foglia = CreateRootTree(e, NULL, NULL);

	while (!IsEmptyTree(n)) {
		if (n->value >= *e)
		{
			if (n->left == NULL) {
				n->left = new_foglia;
				break;
			}
			else
				n = n->left;
		}
		else
		{
			if (n->right == NULL) {
				n->right = new_foglia;
				break;
			}
			else
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

	const ElemType *max = TreeMax(ris);

	return 0;
}