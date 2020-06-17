#include "tree_int.h"

//NON FUNZIONA!!!!!

Node* MaximumKey(Node *n) {
	while (!IsEmptyTree(RightTree(n))) {
		n = RightTree(n);
	}
	return n;
}

Node *DeleteBstNode(Node *n, const ElemType *key)
{
	if (n == NULL)
		return NULL;

	const ElemType *root = GetRootValueTree(n);
	
	Node *head = n;

	Node *padre_dx = NULL;
	Node *padre_sx = NULL;

	while (!IsEmptyTree(n))
	{
		if (n->value == *key) {
			break;
		}
		else if (n->value > *key) {
			padre_sx = n;
			padre_dx = NULL;
			n = n->left;
		}
		else {
			padre_dx = n;
			padre_sx = NULL;
			n = n->right;
		}
	}

	// Se il nodo da eliminare è una foglia
	if (IsLeafTree(n)) 
	{
		if (padre_dx == NULL)
			padre_sx->left = NULL;
		
		else if (padre_sx == NULL)
			padre_dx->right = NULL;

		return head;
	}

	//Se il nodo da eliminare ha un solo figlio
	else if ((n->left != NULL && n->right == NULL) || (n->left == NULL && n->right != NULL))
	{
		Node *next = NULL;

		if (n->left != NULL && n->right == NULL)
			next = n->left;
		else if (n->left == NULL && n->right != NULL)
			next = n->right;

		if (padre_sx != NULL)
			padre_sx = next;
		else if (padre_dx != NULL)
			padre_dx = next;

		if (*root == *key)
			return next;

		return head;
	}

	/* Se il nodo da eliminare ha due figli: 
	devo trovare il il minore tra i nodi maggiori del nodo in questione e sostituirlo con quello da eliminare*/

	
	Node *max = MaximumKey(n->left);
	
	Node *p = n2;
	n2 = n2->right;
	ElemType e = ElemCopy(&max->value);
	DeleteTree(n2);
	p->right = NULL;
	
	if (padre_dx == NULL && padre_sx == NULL) {
		head->value = e;
		return head;
	}

	if (*root == *key)
		return n;

	return head;
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
	const ElemType v[] = { 12 , 4 , 21 , 0, 5, 18, 77, 2, 8, 9 };
	int size = sizeof(v) / sizeof(ElemType);
	int i = 0;

	while (i < size)
	{
		ris = BstInsert(&v[i], ris);
		i++;
	}

	Node *new = DeleteBstNode(ris, &v[2]);

	return 0;
}