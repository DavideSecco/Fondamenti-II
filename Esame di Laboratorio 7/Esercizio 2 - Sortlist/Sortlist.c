#include "list_int.h"

// memory leak!

element trova_minimo(list l)
{
	element min = l->value;
	while (1)
	{
		if (l == NULL)
			return min;

		if (min > l->value)
		{
			element tmp = min;
			min = l->value;
			l->value = tmp;
		}
		l = Tail(l);
	}
}

list SortList(list l)
{
	if (l == NULL)
		return NULL;

	const element min = trova_minimo(l);

	return Cons(&min , SortList(l->next));
}

int main()
{
	return 0;
}