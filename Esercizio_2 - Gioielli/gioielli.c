#include "gioielli.h"

Gioiello *Gioielli(const char* filename, float b, int *ret_size){

	Gioiello *g = malloc(0);

	FILE *p = fopen(filename, "r");

	if (p == NULL)
		return NULL;

	int size = 0;

	while (1)
	{
		int code;
		float w, pes;
		int res = fscanf(p, "%d %f %f", &code, &w, &pes);
		if (res == EOF)
			break;
		size = size + 1;
		g = realloc(g, (size) * sizeof(Gioiello));
		g[size - 1].codice = code;
		g[size - 1].peso = w;
		g[size - 1].prezzo = pes;
	}

	fclose(p);
	
	for (int i = 0; i < size; i++) {
		float max_peso_prezzo = g[i].peso / g[i].prezzo;
		for (int j = i; j < size; j++) {
			float app = g[j].peso / g[j].prezzo;
			if (app > max_peso_prezzo) {
				max_peso_prezzo = app;
				int temp1 = g[i].codice;
				float temp2 = g[i].peso;
				float temp3 = g[i].prezzo;
				memcpy(&g[i], &g[j], sizeof(Gioiello));
				g[j].codice = temp1;
				g[j].peso = temp2;
				g[j].prezzo = temp3;
			}
		}
	}

	int m = 0;
	Gioiello *ret = calloc(1, sizeof(Gioiello));
	for (int i = 0; i < size; i++)
	{
		if (g[i].prezzo <= b)
		{
			m=m+1;
			ret = realloc(ret, m*sizeof(Gioiello));
			memcpy(&ret[m - 1], &g[i], sizeof(Gioiello));
			b = b - g[i].prezzo;
		}
		if (b <= 0)
			break;
	}
	*ret_size = m;
	free(g);
	return ret;
}