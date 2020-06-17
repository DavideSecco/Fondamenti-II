#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void BabboNatale(int p, int const *pacchi, int n, unsigned i, bool *vcurr, bool *vbest, unsigned *max, unsigned cnt, int sum) {

	if (i == n) {
		if (cnt > (*max)) {
			(*max) = cnt;
			memcpy(vbest, vcurr, n * sizeof(bool));
		}
		return;
	}

	vcurr[i] = 0;
	BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, cnt, sum);

	if (sum + pacchi[i] <= p) {
		vcurr[i] = 1;
		BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, cnt + 1, sum + pacchi[i]);
	}
}


int main(void) {

	int p = 20; // Portata della slitta;

	unsigned pacchi[] = { 10, 11, 1, 3, 3 }; // Pesi dei pacchi 
	int n = sizeof(pacchi) / sizeof(unsigned); // Numero dei pacchi

	unsigned max = 0; // Pacchi sono stati caricati dalla soluzione ottima

	bool *vbest, *vcurr;
	vbest = calloc(n, sizeof(bool));  // Soluzione ottima
	vcurr = malloc(n * sizeof(bool)); // Soluzione corrente

	BabboNatale(p, pacchi, n, 0, vcurr, vbest, &max, 0, 0);

	for (int i = 0; i < n; ++i) {
		printf("%d ", vbest[i]);
	}
	printf("\n");

	free(vbest);
	free(vcurr);

	return EXIT_SUCCESS;
}