#include "sciatori.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void choose(double *altezza, double* lunghezze, int size, int *a, int *l)
{
	double best = 10000000;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			double diff = fabs(altezza[i] - lunghezze[j]);
			if (diff < best) {
				best = diff;
				*a = i;
				*l = j;
			}
		}
	}
}

void Greedy(double *altezza, double* lunghezze, int size, sciatore* s)
{
	for (int i = 0; i < size; i++)
	{
		int a, l;
		choose(altezza, lunghezze, size, &a, &l);
		s[i].a = altezza[a];
		s[i].l = lunghezze[l];
		altezza[a] = 1000000;
		lunghezze[l] = -1000000;
	}
}

sciatore* Accoppia(double *altezza, double* lunghezze, int size)
{
	if (size == 0)
		return NULL;

	sciatore* s = malloc(size * sizeof(sciatore));

	Greedy(altezza, lunghezze, size, s);
	return s;
}