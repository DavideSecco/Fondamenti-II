#include "minheap_int.h"
#include <stdlib.h>
#include <string.h>

extern void MoveDownMinHeapRec(Heap *h, int i);

Heap* HeapifyMinHeap(const ElemType *v, size_t v_size)
{
	Heap* h = CreateEmptyHeap();
	h->size = v_size;
	h->data = malloc(sizeof(ElemType)*h->size);

	memcpy(h->data, v, v_size * sizeof(ElemType));

	/*for (int i = (h->size) / 2 - 1; i >= 0; i--)
		MoveDownMinHeap(h, i);*/

	for (int i = (int)(h->size) / 2 - 1; i >= 0; i--)
		MoveDownMinHeapRec(h, i);

	return h;
}

int main()
{
	// Creo un nuovo heap:
	const ElemType v[] = { 0,1,5,8,3,4 };
	size_t size = sizeof(v) / sizeof(ElemType);
	Heap* heap = HeapifyMinHeap(v, size);

	// Aggiungo un elemento e lo metto in fondo al vettore:
	heap->size++;
	heap->data = realloc(heap->data, sizeof(ElemType)*heap->size);
	heap->data[heap->size - 1] = 2;
	MoveDownMinHeapRec(heap, heap->size - 1);
	return 0;
}