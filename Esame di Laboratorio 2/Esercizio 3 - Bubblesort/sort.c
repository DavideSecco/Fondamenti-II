#include <stdbool.h>
#include <stdlib.h>

bool BubbleSort(int *v, int v_size)
{
	if (v == NULL || v_size == 0)
		return false;

	bool ordinato = false;

	while (v_size > 1 && !ordinato)
	{
		ordinato = true;
		for (int i = 0; i < v_size - 1; i++) {
			if (v[i] > v[i + 1]) {
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				ordinato = false;
			}
		}
		v_size--;
	}
	return v;
}