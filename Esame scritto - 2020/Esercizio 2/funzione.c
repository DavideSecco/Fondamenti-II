#include "nodo.h"
#include <stdlib.h>

// si può fare facendo una funzione ricorsiva anche con 1 o 2 parametri? (probabilmente si)

void Back(nodo* n, nodo* prev, nodo* next) {
	
	if (n == NULL)
		return;

	int n_val = n->valore;
	int prev_val = 0;		// li metto a zero perchè potrebbero non esistere!
	int next_val = 0;

	if(prev != NULL)
		prev_val = prev->valore;

	if (next != NULL)
		next_val = next->valore;

	if (n_val == (next_val + prev_val)) {
		// elimina nodo
		prev->next = n->next;
		next->prev = prev;
		free(n);
	}

	Back(n->next, n, next->next);
}

void elimina(nodo *n) {
	if (n->next == NULL);
		return;
	
	// n->prev = NULL perchè immagino vada così (in analogia con l'ultimo)
	Back(n, NULL, n->next);
}