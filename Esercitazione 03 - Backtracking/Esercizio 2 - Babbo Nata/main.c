#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void copia(bool *vcurr, bool *vbest, int n)
{
	for (int i = 0; i < n; i++)
	{
		vbest[i] = vcurr[i];
	}
}

void BabboNatale(int p, int const *pacchi, int n, unsigned i, bool *vcurr, bool *vbest, unsigned *max, unsigned cnt, int sum)
{
	int j = i;

	if (cnt > *max && sum <= p && i == n)
	{
		*max = cnt;
		copia(vcurr, vbest, n); //oppure: memcpy(vbest, vcurr, n*sizeof(bool));
		return;
	}

	if (i == n)
		return;

	if (sum > p)
		return;
	
	vcurr[j] = 1;
	BabboNatale(p, pacchi, n, i+1, vcurr, vbest, max, cnt+1, sum + pacchi[j]);
	vcurr[j] = 0;
	BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, cnt, sum);
}

int main()
{
	int p = 20;
	unsigned pacchi[] = { 10, 11, 1, 3, 3};
	int n = sizeof(pacchi)/sizeof(unsigned);

	bool *vbest, *vcurr;
	vcurr = malloc(n * sizeof(bool));
	vbest = calloc(n, sizeof(bool));
	unsigned max = 0;
	BabboNatale(p, pacchi, n, 0, vcurr, vbest, &max, 0, 0);
	
	for(int i=0; i<n; i++)
		printf("%d ", vbest[i]);
	
	printf("\n");
	
	for (int i = 0; i < n; i++) {
		if (vbest[i] == 1)
			printf("%d ", pacchi[i]);
	}
}