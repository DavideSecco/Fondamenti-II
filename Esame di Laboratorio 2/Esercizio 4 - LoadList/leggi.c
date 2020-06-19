#define _CRT_SECURE_NO_WARNINGS

#include "list_coords.h"
#include <stdio.h>

list LoadList(const char* filename)
{
	FILE *f = fopen(filename, "r");
	
	if (f == NULL)
		return NULL;

	list l = EmptyList();

	while (1)
	{
		int x, y;
		int ris = fscanf(f, "%d %d", &x, &y);
		if (ris != 2)
			break;

		coords p = { x,y };
		l=Cons(&p, l);
	}
	
	fclose(f);
	return l;
}

int main()
{
	list l = LoadList("list_coords01.txt");
	return 0;
}