#include "prezzototale.h"

void back(const articolo* a, size_t size, int sum, bool *vcurr,  size_t i, int sum_curr)
{
	if (size == i)
	{
		if (sum_curr == sum)
		{
			for (size_t j = 0; j < size; j++)
			{
				if (vcurr[j] == 1)
					printf("%s, ", a[j].nome);
			}
			printf("\n");
		}
		return;
	}

	// Non prendo articolo
	vcurr[i] = 0;
	back(a, size, sum, vcurr, i + 1, sum_curr);

	//prendo articolo:
	vcurr[i] = 1;
	sum_curr = sum_curr + a[i].prezzo;
	back(a, size, sum, vcurr, i + 1, sum_curr);
}

void TrovaArticoli(const articolo* a, size_t a_size, int sum) {
	
	if (a_size <= 0)
		return;

	bool* vcurr = malloc(a_size * sizeof(bool));
	back(a, a_size, sum, vcurr, 0, 0);
	free(vcurr);
}

int main()
{
	const articolo a[] = { {"prova", 3}, {"prova_2", 5}, {"prova_3", 8} };
	size_t size = sizeof(a) / sizeof(articolo);
	TrovaArticoli(a, size, 8);
	return 0;
}