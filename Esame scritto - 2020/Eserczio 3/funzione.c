#include "tree_int.h"

void Back(Node* t, bool* f) {
	
	if (*f == false)
		return;
	
	if (IsEmptyTree(t) || IsLeafTree(t));
		return;

	ElemType sx_val = -10000;
	ElemType dx_val = 100000;
	Node* sx = NULL;
	Node* dx = NULL;

	if (t->left != NULL) {
		sx = t->left;
		sx_val = sx->value;
	}

	if (t->right != NULL) {
		dx = t->right;
		dx_val = dx->value;
	}
	
	if (t->value < sx_val || t->value > dx_val) {
		*f = false;
		return;
	}

	if (sx != NULL)
		Back(sx, f);

	if (dx != NULL)
		Back(dx, f);
}

bool isTreeBst(Node *t) {
	bool* f = true;
	Back(t, f);
}