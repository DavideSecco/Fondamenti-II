#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <stdio.h>

void copy(int *vbest, int *vcurr, int n)
{
	for (int i = 0; i < n; i++)
	{
		vbest[i] = vcurr[i];
	}
}

void funz(double m, int n, double *d, double *p, int i, int *vcurr, int *vbest, double spesa, double *spesa_best, double autonomia, double tot_km)
{
	autonomia = autonomia - d[i];

	if (autonomia < 0)
		return;

	tot_km = tot_km + d[i];

	if (tot_km + autonomia >= m)
	{
		if (spesa < *spesa_best)
		{
			copy(vbest, vcurr, n);
			*spesa_best = spesa;
		}
		return;
	}

	if (i == n)
		return;

	//se non ti fermi
	vcurr[i] = 0;
	funz(m, n, d, p, i + 1, vcurr, vbest, spesa, spesa_best, autonomia, tot_km);
	
	//se ti fermi
	spesa = spesa + (600-autonomia)*0.05*p[i];
	autonomia = 600;
	vcurr[i] = 1;
	funz(m, n, d, p, i + 1, vcurr, vbest, spesa, spesa_best, autonomia, tot_km);
}

void StazioniServizio(double m, int n, double *d, double *p)
{
	int *vcurr = calloc(n, sizeof(int));
	int *vbest = calloc(n, sizeof(int));
	double spesa_best = DBL_MAX;
	double tot_km = 0;
	funz(m, n, d, p, 0, vcurr, vbest, 0, &spesa_best, 600, tot_km);
	
	if (spesa_best == DBL_MAX)
		printf("Non esistono soluzioni");
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (vbest[i] == 1)
				printf("%d ", i);
		}
		printf("\nspesa totale = %f", spesa_best);
	}

	free(vcurr);
	free(vbest);
}