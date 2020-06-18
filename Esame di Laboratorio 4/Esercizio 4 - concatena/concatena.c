#include "list_int.h"

list back(list *ls, int ls_size, int i)
{
	if (i == ls_size)
		return NULL;

	if (ls[i] == NULL)
		return back(ls, ls_size, i + 1);

	if (i == ls_size - 1)
		return ls[i];
	
	list head = ls[i];
	while (!IsEmpty((ls[i]->next)))
	{
		ls[i] = Tail(ls[i]);
	}

	ls[i]->next = back(ls, ls_size, i + 1);

	return head;
}

list Concatena(list *ls, int ls_size)
{
	if (ls_size == 0)
		return EmptyList();

	list t = back(ls, ls_size, 0);
	return t;
}