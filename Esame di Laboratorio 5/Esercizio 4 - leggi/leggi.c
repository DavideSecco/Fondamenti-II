#define _CRT_SECURE_NO_WARNINGS

#include "list_coords.h"
#include <stdio.h>

list LoadList(const char* filename)
{
	FILE *f = fopen(filename, "r");
	
	list l = EmptyList();

	if (f == NULL)
		return l;	

	while (1)
	{
		float x, y;
		int ris = fscanf(f, "%f%f", &x, &y);
		
		if (ris != 2)
			break;

		coords p = { x,y };

		l = Cons(&p, l);
	}
	fclose(f);
	return l;
}

int main()
{
	list l = LoadList("list_coords01.txt");
	return 0;
}