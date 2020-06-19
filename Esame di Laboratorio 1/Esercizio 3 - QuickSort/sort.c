#include <stdbool.h>
#include <stdlib.h>

void Back(int *v, int first, int last)
{
	int i, j, pivot;
	if (first < last) {
		i = first;
		j = last;
		pivot = v[(first + last) / 2];
		do {
			while (v[i] < pivot)
				i++;
			while (v[j] > pivot)
				j--;
			if (i <= j) {
				int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
				i++;
				j--;
			}
		} while (i <= j);
		Back(v, first, j);
		Back(v, i, last);
	}
}

bool QuickSort(int *v, int v_size, int first, int last)
{
	if (first < 0 || last >= v_size || last < first || v == NULL)
		return false;

	Back(v, first, last);
	return true;
}