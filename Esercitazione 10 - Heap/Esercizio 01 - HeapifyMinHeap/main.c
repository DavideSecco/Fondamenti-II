#include "minheap_int.h"

extern Heap* HeapifyMinHeap(const ElemType *v, size_t v_size);

int main()
{
	const ElemType v[] = { 0,1,5,8,2,4,0,4 };
	size_t size = sizeof(v) / sizeof(ElemType);

	Heap* r = HeapifyMinHeap(v, size);

	return 0;
}