#include "list_int.h"

Item* CopiaDaN(const Item* i, int n) {
	Item* t = CreateEmptyList();
	
	if (IsEmptyList(i))
		return t;

	int size = 1;

	while (!IsEmptyList(i)) {
		if (size == n)
			break;
		size++;
		i = GetTailList(i);
	}

	while (!IsEmptyList(i)) {
		t = InsertBackList(t, &i->value);
		i = GetTailList(i);
	}

	return t;
}