#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//si può ottimizzare molto meglio! guarda soluzione sul sito!

int isvalid(bool *vcurr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (vcurr[i] == 1 && vcurr[i + 1] == 1 && i < (n - 1))
			return 1;
	}
	return 0;
}

void Ombrelloni(int k, int n, unsigned i, bool *vcurr, unsigned cnt, unsigned int *nsol)
{
	int j=i;

	if (cnt != k && i==n)
		return;

	if (cnt == k && i==n)
	{
		int g=isvalid(vcurr, n);
		if (g == 1)
			return;
		printf("\n %u) ", *nsol);
		*nsol = *nsol + 1;
		for (j = 0; j < n; j++)
		{
			printf("%d ", vcurr[j]);
		}
		return;
	}

	vcurr[j] = false;
	Ombrelloni(k, n, i + 1, vcurr, cnt, nsol);
	vcurr[j] = true;
	Ombrelloni(k, n, i + 1, vcurr, ++cnt, nsol);
}

int main()
{
	int n = 4;
	int k = 2;
	bool *vcurr = malloc(n*sizeof(bool));
	unsigned nsol = 1;
	Ombrelloni(2, 4, 0, vcurr, 0, &nsol);
}