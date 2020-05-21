#include "list_int.h"
#include <stdlib.h>

extern Item* Diff(const Item* i1, const Item* i2)
{
	Item *head = malloc(sizeof(Item));
	head->next = NULL;
	Item *i = head;	
	
	Item *rec = i;

	//serve per controllo che ci sia almeno un elemento nella lista
	bool f2 = false; 

	while (1)
	{
		//controllo se sono arrivato alla fine di i1
		if (i1 == NULL)
			break; 

		//uso un altro puntatore per scorrere i2
		const Item *tmp = i2;

		//flag per controllare se ci sono elementi uguali
		bool f = true;

		// scorro tmp (cioè i2)
		while (1)
		{
			if (tmp == NULL)
				break;

			//se due elementi sono uguali, esco da ciclo:
			if (ElemCompare(&i1->value, &tmp->value)==0){
				f = false;
				break;
			}

			tmp = tmp->next;	
		}

		//se non c'è l'elemento in i2, lo salvo nell'altra lista
		if (f == true){
			f2 = true;
			Item* t = malloc(sizeof(Item));
			i->value = i1->value;
			rec = i;
			i->next = t;
			i = i->next;
		}

		i1 = i1->next;
	}
	
	ElemDelete(&i->value);
	ElemDelete(&i->value);
	free(i);

	//non ci sono elementi nella lista --> ritorno la lista vuota
	if (f2 == false){
		head = NULL;
	}

	// ci sono elementi nella lista --> allora l'ultimo elemento i->next = NULL;
	else{
		rec->next = NULL;
	}

	return head;
}