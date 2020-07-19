#include "minheap_int.h"
#include <string.h>
#include <stdlib.h>

int main() {

	ElemType v[] = { 1,2,3,4,5 };
	int v_size = sizeof(v) / sizeof(ElemType);
	Heap* h = CreateEmptyHeap();
	h->size = v_size;
	h->data = malloc(sizeof(ElemType)*v_size);
	memcpy(h->data, v, sizeof(ElemType)*v_size);

	for (int i = h->size / 2 - 1; i >= 0; i--) {
		MoveDownMinHeap(h, i);
	}


}