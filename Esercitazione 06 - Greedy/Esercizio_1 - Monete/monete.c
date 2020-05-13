#include <stdlib.h>

int* Monete(int *t, int size, int b) {
	
	if (b <= 0)
		return NULL;

	int *best = calloc(size, sizeof(int));

	while (1)
	{
		if (b == 0)
			break;

		for (int i = 0; i < size; i++)
		{
			if (t[i] <= b)
			{
				best[i] = best[i] + 1;
				b = b - t[i];
				break;
			}
		}
	}

	return best;
}