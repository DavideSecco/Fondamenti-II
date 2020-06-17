#define _CRT_SECURE_NO_WARNINGS

#include "list_int.h"
#include <stdlib.h>

Item* Diff(const Item* i1, const Item* i2)
{
	if (i1 == NULL)
		return NULL;

	//if(i2 == NULL)
		//return i1;

	Item* i3 = NULL;
	Item* head = i3;
	const Item* tmp_1 = i1;
	const Item* tmp_2 = i2;

	bool s = false; //indica la fine della prima lista

	while (s == false)
	{
		bool f = false;
		ElemType e1 = ElemCopy(&tmp_1->value);

		if (tmp_1->next == NULL)
			s = true;

		tmp_2 = i2;

		while (tmp_2 != NULL)
		{
			ElemType e2 = ElemCopy(&tmp_2->value);
			if (e1 == e2) {
				f = true;
				break;
			}
			tmp_2 = tmp_2->next;
		}

		// aggiungo il numero se non è stato trovato in i2
		if (f == false)
		{
			Item *t = malloc(sizeof(Item));
			t->value = e1;
			t->next = i3;
			i3 = t;
		}
		tmp_1 = tmp_1->next;
	}

	return i3;
}