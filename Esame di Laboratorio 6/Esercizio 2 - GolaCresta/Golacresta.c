#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool check_1(int *v, int i)
{
	//if ((*(v + i) < *(v + i + 1)) && (v[i + 1] > v[i + 2]))
	if ((v[i] < v[i+1]) && (v[i + 1]>v[i + 2]))
		return true;

	if (v[i] > v[i + 1] && v[i + 2] > v[i + 1])
		return true;

	return false;
}

void stampa(int *v, size_t n)
{
	printf("(");
	for (size_t i = 0; i < n; i++)
	{
		if (i == (n - 1))
			printf("%d", v[i]);
		else
			printf("%d, ", v[i]);
	}
	printf("), ");
}

void back(size_t n, int i, int* vcurr, int* numeri)
{
	// caso base;
	if (i == n) {   

		bool f1 = false;
		for (int a = 0; a + 2 < n; a++)
		{
			f1 = check_1(vcurr, a);
			if (f1 == false)
				break;
		}
		
		if (f1 == true)
			stampa(vcurr, n);

		return;
	}

	for (int j = 0; j < 3; j++) {
		vcurr[i] = numeri[j];
		back(n, i + 1, vcurr, numeri);
	}
}

void GolaCresta(size_t n)
{
	if (n < 3)
		return;

	int* vcurr = malloc(n * sizeof(int));
	int numeri[3] = { 0,1,2 };
	back(n, 0, vcurr, numeri);
	free(vcurr);
}

int main()
{
	GolaCresta(4);
	return 0;
}