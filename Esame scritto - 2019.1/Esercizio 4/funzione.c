#include "list_int.h"
#include <stdlib.h>

// funzione che salva i nodi in un vettore (dim. size)
void carico_nodi(Item* l, int* v, int* size) {
	if (IsEmptyList(l))
		return;

	*size++;
	v = realloc(v, *size * sizeof(int));
	v[*size - 1] = l->value;
	carico_nodi(l->next, v, size);
}

// funzione che calcola la somma dei nodi da un nodo a a un nodo b
int calcola_somma(int* v, int* a, int* b) {
	
	int somma = 0;

	for (int i = *a; i < *b; i++) 
		somma = somma * v[i];

	return somma;
}

void nodi_somma(int* v, int size, int* a, int* b, int s_curr, int k, bool* trovato) {

	if (*b == size) // sono arrivato alla fine del vettore
		return;
	
	// trovato!
	if (s_curr == k) {
		*trovato = true;
		return;
	}

	if (s_curr < k) {
		*b++;
		if (*b == size)
			return;
		s_curr = calcola_somma(v, a, b);
		nodi_somma(v, size, a, b, s_curr, k, trovato);
	}

	if (s_curr > k) {
		*a++;
		s_curr = calcola_somma(v, a, b);
		nodi_somma(v, size, a, b, s_curr, k, trovato);
	}
}

Item* SeekAndDestroy(Item* l, int k) {
	if (IsEmptyList(l))
		return l;

	Item* head = l;
	int* v = NULL;
	int size = 0;
	carico_nodi(l, v, &size);

	int a = 0;
	int b = 0;
	bool* trovato = false;
	nodi_somma(v, size, &a, &b, 0, k, trovato);

	if (*trovato == false) {
		printf("NON CI SONO NODI CHE HANNO QUELLA SOMMA");
		return l;
	}

	int i;

	for (i = 0; i < a; i++) {
		l = GetTailList(l)
	}

	Item* tmp = l;

	for (; i< b; i++) {
		Item* tmp2 = l;
		l = l->next;
		ElemDelete(&tmp2->value);
		free(tmp2);
	}

	tmp->next = l;
	return head;
}