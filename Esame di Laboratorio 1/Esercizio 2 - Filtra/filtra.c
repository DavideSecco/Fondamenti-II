#include "liste_indirizzo.h"
#include <string.h>

list Filtra(list l, const char* citta)
{
	if (IsEmpty(l))
		return NULL;
	
	list t = EmptyList();
	while(!IsEmpty(l))
	{
		if (strcmp(l->value.citta, citta) != 0) 
			t = InsertBack(t, &l->value);
		l = Tail(l);
	}

	return t;
}

int main()
{
	element e;
	*e.citta = "Mod";
	list l = EmptyList();
	l = Cons(&e, l);
	list l1 = Filtra(l, 'Mod');
}
