#include "tree_int.h"

// MOLTO DIFFICILE: PUNTATORE A PUNTATORE

void funzione(const ElemType **min, const Node *n)
{
	if (*min == NULL ||  **min > n->value)
		*min = &n->value;
	
	if (n->left != NULL)
		funzione(min, n->left);
	if (n->right != NULL)
		funzione(min, n->right);

	return;
}

const ElemType* MinTree(const Node *n)
{
	if (n == NULL)
		return NULL;

	const ElemType *min = NULL;

	funzione(&min, n);

	return min; 
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
	const ElemType v[] = { 12 , 4 , 21 , 3, 5, 18, 77, 2, 8, 6, 9 };
	int size = sizeof(v) / sizeof(ElemType);
	int i = 0;

	while (i < size)
	{
		ris = BstInsert(&v[i], ris);
		i++;
	}

	const ElemType *min = MinTree(ris);

	return 0;
}