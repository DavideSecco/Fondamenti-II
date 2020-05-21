#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"

Item* LoadList(const char *filename) {
	FILE *f = fopen(filename, "r");

	Item *i = CreateEmptyList();

	if (f == NULL)
		return i;

	while (1)
	{
		ElemType e;
		int  ris = fscanf(f, "%d", &e);

		if (ris == EOF)
			break;

		i = InsertHeadList(&e, i);
	}

	fclose(f);

	return i;
}
