#include "tree_int.h"

// Nel compito la def di nodo è diversa... ma siamo li...
// NON E' STATO TESTATO

int ContaDominanti(Node* t) {
	
	if (IsEmptyTree(t) || IsLeafTree(t))
		return 0;
	
	ElemType sx_val = 0;
	ElemType dx_val = 0;

	if (t->left != NULL)
		sx_val = GetRootValueTree(LeftTree(t));

	if (t->right != NULL)
		dx_val = GetRootValueTree(RightTree(t));

	if (t->value > (dx_val + sx_val))
		return 1 + ContaDominanti(LeftTree(t)) + ContaDominanti(RightTree(t)));
	else
		return 0 + ContaDominanti(LeftTree(t)) + ContaDominanti(RightTree(t)));
}