#include "tree_int.h"
#include <stdbool.h>

bool multipli(const ElemType* e1, const ElemType* e2) {
	int resto;
	if (*e1 >= *e2)
		resto = *e1 % *e2;
	else
		resto = *e2 % *e1;
	if (resto == 0)
		return true;
	else
		return false;
}

void Back(const Node* t1, const Node* t2, bool* f) {
	
	if (*f == false)
		return;

	// controllo che siano entrambi foglie o entrambi non foglie
	if (( IsLeafTree(t1) && !IsLeafTree(t2)) || (!IsLeafTree(t1) && IsLeafTree(t2)))
		*f = false;

	// controllo (se non sono foglie) che abbiano il valore uguale
	if (!IsLeafTree(t1) && !IsLeafTree(t2)) {
		if (t1->value != t2->value)
			*f = false;
	}
	
	if (*f == false)
		return;
	
	// Se sono entrabe foglie, controllo che siano multiple una dell'altra
	if (IsLeafTree(t1) && IsLeafTree(t2)) {
		bool f1 = multipli(&t1->value, &t2->value);
		if (f1 == true)
			return;
		else {
			*f = false;
			return;
		}
	}

	if (*f == false)
		return;

	if (t1->left != NULL && t2->left != NULL)
		Back(t1->left, t2->left, f);
	if (t1->right != NULL && t2->right != NULL)
		Back(t1->right, t2->right, f);

	if (*f == false)
		return;
}

bool Equivalenti(const Node* t1, const Node* t2) {
	if (IsEmptyTree(t1) && IsEmptyTree(t2))
		return true;

	if (IsEmptyTree(t1))
		return false;

	if (IsEmptyTree(t2))
		return false;

	bool f = true;

	Back(t1, t2, &f);

	return f;
}