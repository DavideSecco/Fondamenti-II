#include "minheap_int.h"

Heap* HeapifyMinHeap(const ElemType *v, size_t v_size)
{
	Heap* heap = CreateEmptyHeap();
	if (v == NULL || v_size <= 0)
		return heap;

	for (int i = 0; i < v_size; i++)
	{
		InsertNodeMinHeap(heap, &v[i]);
	}

	return heap;
}