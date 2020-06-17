#include "tree_int.h"

void funzione(const Node *root, int *count)
{
	if (IsLeafTree(root))
		return;

	const Node *n1 = LeftTree(root);
	const Node *n2 = RightTree(root);
	
	ElemType s1 = 0;
	ElemType s2 = 0;

	if (n1 != NULL)
		s1 = n1->value;
	if (n2 != NULL)
		s2 = n2->value;

	ElemType somma = s1 + s2;

	if (somma < root->value)
		*count = *count + 1;

	funzione(n1, count);
	funzione(n2, count);
}

extern int CountDominant(const Node* t)
{
	if (t == NULL)
		return 0;

	int count = 0;
	funzione(t, &count);

	return count;
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
	// Usato per creare un albero
	Node *ris = NULL;
	const ElemType v[] = { 12 , 4 , 21 , 0, 5, 18, 77, 2, 8, 6, 9 };
	int size = sizeof(v) / sizeof(ElemType);
	int i = 0;

	while (i < size)
	{
		ris = BstInsert(&v[i], ris);
		i++;
	}
	//

	int c = CountDominant(ris);
	return 0;
}