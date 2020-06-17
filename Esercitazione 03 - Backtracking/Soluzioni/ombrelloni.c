#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//void Ombrelloni(int k, int n, unsigned i, bool *vcurr, unsigned cnt, unsigned *nsol) {
//
//	// Caso base
//	if (i == n) {
//		// Verifica il numero di ragazzi posizionati
//		if (cnt != k) {
//			return;
//		}
//
//	    // Verifica eventuali ragazzi adiacenti
//	    for (int i = 0; i < n - 1; ++i) {
//	    	if (vcurr[i] == 1 && vcurr[i + 1] == 1) {
//	    		return;
//	    	}
//	    }
//
//		// Stampa e conta la soluzione 
//		(*nsol)++;
//		printf("%4d) ", (*nsol));
//		for (int j = 0; j < n; ++j) {
//			printf("%d ", vcurr[j]);
//		}
//		printf("\n");
//		return;
//	}
//
//
//	vcurr[i] = 0; // Lascio libero l'ombrellone corrente
//	Ombrelloni(k, n, i + 1, vcurr, cnt, nsol);
//
//	vcurr[i] = 1; // Posiziono un ragazzo nell'ombrellone corrente
//	Ombrelloni(k, n, i + 1, vcurr, cnt + 1, nsol);
//}

void Ombrelloni(int k, int n, unsigned i, bool *vcurr, unsigned cnt, unsigned *nsol) {

	// Caso base
	if (cnt == k) {
		// Stampa e conta la soluzione 
		(*nsol)++;
		printf("%4d) ", (*nsol));

		memset(vcurr + i, 0, (n - i) * sizeof(bool));

		for (int j = 0; j < n; ++j) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}

	// Caso base
	if (i == n) {
		return;
	}

	vcurr[i] = 0; // Lascio libero l'ombrellone corrente
	Ombrelloni(k, n, i + 1, vcurr, cnt, nsol);

	if (i == 0 || (i > 0 && vcurr[i - 1] == 0)) {
		vcurr[i] = 1; // Posiziono un ragazzo nell'ombrellone corrente
		Ombrelloni(k, n, i + 1, vcurr, cnt + 1, nsol);
	}
}


int main(void) {

	int n = 6; // Ombrelloni in prima fila
	int k = 2; // Numero di ragazzi

	unsigned nsol = 0; // Numero soluzioni
	bool *vcurr = malloc(n * sizeof(bool)); // Soluzione corrente

	Ombrelloni(k, n, 0, vcurr, 0, &nsol);

	free(vcurr);

	return EXIT_SUCCESS;
}
