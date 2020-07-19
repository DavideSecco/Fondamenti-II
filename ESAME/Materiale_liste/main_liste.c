#include "list_int.h"
#include <stdlib.h>

int main()
{
	ElemType e1[] = { 1,2,3,4,5 };
	ElemType e2[] = { 2,3,5,6 };

	int s1 = sizeof(e1) / sizeof(ElemType);
	int s2 = sizeof(e2) / sizeof(ElemType);

	Item* l1 = CreateEmptyList();
	Item* l2 = CreateEmptyList();

	for (int i = 0; i < s1; i++)
		l1 = InsertBackList(l1, &e1[i]);

	for (int i = 0; i < s2; i++)
		l2 = InsertBackList(l2, &e2[i]);

	return 0;
}