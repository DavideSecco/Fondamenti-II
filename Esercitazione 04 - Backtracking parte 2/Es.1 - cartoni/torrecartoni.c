#include "torrecartoni.h"

void def(int *v, int n)
{
	for (int i = 0; i < n; i++)
	{
		v[i] = -1;
	}
}

void copia(int *vbest, int *vcurr, int n)
{
	for (int i = 0; i < n; i++)
	{
		vbest[i] = vcurr[i];
	}
}

int check(int *v, int n, int a)
{
	for (int i = 0; i < n; i++)
	{
		if (v[i] == a)
			return 1;
	}
	return 0;
}

void ordina(cartone *c, int n, int *vcurr, int i, int *h_best, int h_curr, int *vbest, unsigned p_curr)
{
	if (i == n)
		return;
	
	//scorrere in orizzontale per provare tutte le soluzioni nella i-esima posizione
	for (int a = 0; a < n; a++)
	{
		//devo controllare se quel cartone non è già stato usato
		int f = check(vcurr, n, a); 

		//controllo che fino a quel punto il peso non superi la portata del pacco successivo, altrimenti lo scarto
		if (c[a].l >= p_curr && f==0)
		{
			vcurr[i] = a;
			h_curr = h_curr + c[a].a;
			if (*h_best < h_curr)
			{
				*h_best = h_curr;
				copia(vbest, vcurr, n);
			}
			ordina(c, n, vcurr, i + 1, h_best, h_curr, vbest, p_curr + c[a].p);
			h_curr = h_curr - c[a].a;
		}
	}
}

void TorreCartoni(cartone *c, int n)
{
	int *vcurr = malloc(n*sizeof(int));
	int *vbest = malloc(n*sizeof(int));
	def(vcurr, n); //metto il vettore a -1 così da riconoscere i cartoni assegnati
	int *h_best = malloc(sizeof(int));
	*h_best = 0;
	
	ordina(c, n, vcurr, 0, h_best, 0, vbest, 0);
	for (int a = 0; a < n; a++)
	{
		if(vbest[a]<n && vbest[a]>=0)
			printf("%d\n", vbest[a]);
	}
	printf("altezza : %d", *h_best);
	free(h_best);
	free(vcurr);
	free(vbest);
}

