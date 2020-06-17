#include "minheap_int.h"
#include <stdlib.h>
#include <string.h>

Heap* HeapifyMinHeap(const ElemType *v, size_t v_size)
{
	// Creo l'heap da restituire e predispongo l'heap per contenere tutti i valori
	Heap* h = CreateEmptyHeap();
	h->size = v_size;
	h->data = malloc(sizeof(ElemType)*h->size);
	
	memcpy(h->data, v, v_size * sizeof(ElemType));	// Copio il vettore nell'heap --> andrà ordinato

	/* Devo ordinare con la funzione MoveDown: la funzione sulle foglie non fa nulla, quindi posso 
	implementare la funzione sulla metà "sinistra" del vettore andando da dx a sx:
	In pratica utilizzo MoveDown su tutti i nodi che non sono foglie */

	for (int i = (h->size) / 2 - 1; i >= 0; i--)
		MoveDownMinHeap(h, i);

	return h;
}