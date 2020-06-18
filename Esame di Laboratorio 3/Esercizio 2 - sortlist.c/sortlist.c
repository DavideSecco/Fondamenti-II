#include "list_int.h"

list SortList(list l)
{
	list tmp1 = l;
	list tmp2 = l;

	while (!IsEmpty(tmp1))
	{
		tmp2 = Tail(tmp1);
		while (!IsEmpty(tmp2))
		{
			if (tmp2->value < tmp1->value) {
				element t = tmp1->value;
				tmp1->value = tmp2->value;
				tmp2->value = t;
			}
			tmp2 = Tail(tmp2);
		}
		tmp1 = Tail(tmp1);
	}
	return l;
}