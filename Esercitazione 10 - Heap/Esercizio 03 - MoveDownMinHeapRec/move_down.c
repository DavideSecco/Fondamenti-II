#include "minheap_int.h"

void MoveDownMinHeapRec(Heap *h, int i)
{
	if (IsEmptyHeap(h))
		return;

	int l = LeftHeap(i);
	int r = RightHeap(i);
	int largest = i;

	if ((l < (int)h->size) && ElemCompare(GetNodeValueHeap(h, l), GetNodeValueHeap(h, largest)) < 0) {
		largest = l;
	}

	if ((r < (int)h->size) && ElemCompare(GetNodeValueHeap(h, r), GetNodeValueHeap(h, largest)) < 0) {
		largest = r;
	}

	if (largest != i) {
		ElemSwap(GetNodeValueHeap(h, i), GetNodeValueHeap(h, largest));
		MoveDownMinHeapRec(h, largest);
	}
	else
		return;
}