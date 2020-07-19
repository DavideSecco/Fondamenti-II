#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// il programma NON è stato testato! per l'esame non è importante che compili ecc, basta che l'algoritmo sia giusto

typedef struct {
	int Numero;
	float CostoUnitario;
	float Guadagno;
} Azione;

void Back(Azione* a, int budget, int speso, int* best_guadagno, int curr_guadagno, int size, int i, bool* vcurr, bool* vbest) {
	if (speso > budget)
		return;
	
	if (curr_guadagno > *best_guadagno) {
		*best_guadagno = curr_guadagno;
		memcpy(vbest, vcurr, size * sizeof(bool));
		return;
	}

	if (i == size)
		return;

	// Non prendo il pacchetto di azioni:
	vcurr[i] = false;
	Back(a, budget, speso, best_guadagno, curr_guadagno, size, i + 1, vcurr, vbest);

	// prendo il pacchetto di azioni:
	vcurr[i] = true;
	speso = speso + a[i].Numero* a[i]. CostoUnitario;
	curr_guadagno = curr_guadagno + a[i].Guadagno;
	Back(a, budget, speso, best_guadagno, curr_guadagno, size, i + 1, vcurr, vbest);
}

void funzione(Azione* a, int budget) {
	if (budget <= 0)
		return;

	int soldi_spesi = 0;
	int best_guadagno = 0;
	int curr_guadagno = 0;
	int size = sizeof(a) / sizeof(Azione);
	bool* vcurr = malloc(size * sizeof(bool));
	bool* vbest = malloc(size * sizeof(bool));
	Back(a, budget, soldi_spesi, &best_guadagno, curr_guadagno, size, 0, vcurr, vbest);

	for (int i = 0; i < size; i++) {
		if (vbest[i] == true);
	}
}