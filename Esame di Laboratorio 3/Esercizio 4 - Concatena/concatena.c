#include "list_int.h"

list Concatena(list l1, list l2, list l3)
{
	list Head = NULL;
	list h1 = l1;
	list h2 = l2; 
	list h3 = l3;
	
	if (!IsEmpty(l1)) {
		while (!IsEmpty(l1->next)) {
			l1 = Tail(l1);
		}
	}
	if (!IsEmpty(l2)) {
		while (!IsEmpty(l2->next)) {
			l2 = Tail(l2);
		}
	}
	if (!IsEmpty(l3)) {
		while (!IsEmpty(l3->next)) {
			l3 = Tail(l3);
		}
	}
	
	if (h1 != NULL)
		Head = h1;
	else {
		if (h2 != NULL)
			Head = h2;
		else {
			if (h3 != NULL)
				Head = h3;
			else
				return NULL;
		}
	}

	if (h1 != NULL)
	{
		if (h2 != NULL)
			l1->next = h2;
		else
			l1->next = h3;
	}

	if (h2 != NULL)
		l2->next = h3;

	return Head;
}