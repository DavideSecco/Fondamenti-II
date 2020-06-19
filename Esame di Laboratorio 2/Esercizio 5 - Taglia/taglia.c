#include "list_coords.h"

// c'è memory leak --> non sai eliminare la lista

list Taglia(list l, int n)
{
	if (n <= 0)
		return l;
	if (IsEmpty(l) || n == 1)
		return NULL;

	list head = l;
	list p;
	for (int i = 1; i < n; i++)
	{
		p = l;
		l = Tail(l);
		if (IsEmpty(l))
			return head;

	}

	list delete = l;
	p->next = NULL;
	free(delete);
	return head;
}