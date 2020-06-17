#include "minheap_int.h"

void MoveUpMinHeapRec(Heap *h, int i)
{
	if (i == 0)
		return;

	if (ElemCompare(GetNodeValueHeap(h, i), GetNodeValueHeap(h, ParentHeap(i))) < 0) {
		ElemSwap(GetNodeValueHeap(h, i), GetNodeValueHeap(h, ParentHeap(i)));
		MoveUpMinHeapRec(h, ParentHeap(i));
	}
}