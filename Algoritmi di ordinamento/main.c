#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void selection_sort(int *v, int size);
void bubble_sort(int *v, int size);
void insertion_sort(int *v, int size);
void quicksort(int *v, int first, int last);
void mergeSort(int *v, int first, int last);

int main() {

	int array[5] = { 30, 16, 9, 4, -5 };
	// selection_sort(array, 5);
	// bubble_sort(array, 5);
	// insertion_sort(array, 5);
	// quicksort(array, 0, 5 - 1);
	 mergeSort(array, 0, 5 - 1);

	// ma grazie carzaccolo

	for (int i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}

	return 0;

}

void merge(int v[], int i1, int i2, int last)
{
	int *vout = malloc(last * sizeof(int)); /* vettore temporaneo */
	int i = i1, j = i2;
	int k = i1;
	while (i <= i2 - 1 && j <= last) {
		if (v[i] < v[j])
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}

	while (i <= i2 - 1) {
		vout[k] = v[i++];
		k++;
	}

	while (j <= last) { 
		vout[k] = v[j++]; 
		k++; 
	}

	for (i = i1; i <= last; i++) 
		v[i] = vout[i];
	
}

void mergeSort(int v[], int first, int last) {
	
	if (first < last) {
		int mid = (last + first) / 2;
		mergeSort(v, first, mid);
		mergeSort(v, mid + 1, last);
		merge(v, first, mid + 1, last);
	}
}



void quicksort(int *v, int first, int last) {
	/*
		1. I parametri passati devono essere first < last, e li memorizzo in due variabili i e j
		2. Scelgo un indice pivot, che si troverà a metà vettore
		3. Ciclo (finchè i <= j) con doppio ciclo interno: trovo il primo valore che è maggiore nella parte sx del pivot e il minore nella parte dx
		4. Se i due indice sono i <= j li scambi
		5. Richiami il quicksort con (v, first, j) e (v, i, last);
	*/

	if (first < last) {

		int i = first;
		int j = last;
		int pivot = (i + j) / 2;
		
		do {
			while (v[i] < v[pivot])
				i++;
			while (v[j] > v[pivot]) 
				j--;
			if (i <= j) {
				int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
				i++;
				j--;
			}
		} while (i <= j);

		quicksort(v, first, j);
		quicksort(v, i, last);
	}
}

void insertion_sort(int *v, int size) {

	/*
		PROBABILMENTE IL PIU' BELLO
		1. Analizzo, per ogni elemento dell'array, tutti gli elementi che sono dopo di esso. (Doppio ciclo)
		2. Suppongo quindi che a sinistra dell'elemento che sto analizzando, l'array sia ordinato.
		3. Se trovo che l'elemento è più grande di quello in questione, vorrà dire che non sono in ordine, pertanto vanno scambiati.
		4. Alla fine in v[i] ci sarà il valore minore, poi ricomincio.
	*/

	for (int i = 0; i < size; i++) {

		for (int k = i; k < size; k++) {

			if (v[i] > v[k]) {

				int tmp = v[i];
				v[i] = v[k];
				v[k] = tmp;

			}
		}
	}
}

void bubble_sort(int *v, int size)
{
	// 1. Finche size non è 1 oppure il vettore non è ordinato ---> fai il ciclo
	// 2. Ogni volta partendendo dall'inizio del vettore, scorri tutto il vettore e analizza le coppie di valori adiacenti che vanno invertite
	// 3. Ogni volta in fondo arriverà il valore più grande per cui ---> diminuisci size

	bool ordinato = false;
	while (size > 1 && !ordinato) {
		ordinato = true; /* hp: è ordinato */
		for (int i = 0; i < size - 1; i++)
			if (v[i] > v[i + 1]) {
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				ordinato = false;
			}
		size--;
	}
}

void selection_sort(int *v, int size)
{
	// 1. Salvo l'indice del primo elemento da ordinare in min
	// 2. Dall'elemento dopo in poi, confronto se sono minori, se lo sono, l'indice dell'elemento min = j 
	// 3. Arrivato alla fine in min ci sarà l'indice del valore minore del vettore
	// 4. Scambio i due valori e ricomincio con i + 1.

	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (v[min] > v[j])
				min = j;
		}

		int tmp = v[i];
		v[i] = v[min];
		v[min] = tmp;
	}
}