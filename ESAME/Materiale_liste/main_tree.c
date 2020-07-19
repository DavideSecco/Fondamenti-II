#include "tree_int.h"

int main(void)
{
	ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	Node* n = CreateRootTree(&v[5],
		CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()),
		CreateRootTree(&v[10], CreateEmptyTree(), CreateEmptyTree())
	);


	DeleteTree(n);
}