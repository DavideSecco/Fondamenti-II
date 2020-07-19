#define _CRT_SECURE_NO_WARNINGS

#include "piatto.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Back(piatto* p, int N, int cod_piatto, int cal, char** vcurr) {
	
	if (cod_piatto == 4) {
		if (cal == 700) {
			for (int i = 0; i < 3; i++) {
				printf("%s ", vcurr[i]);
			}
			printf("\n");
		}
		return;
	}

	for (int j = 0; j < N; j++) {
		if (p[j].tipologia == cod_piatto) {
			strcpy(vcurr[j], p[j].nome);
			Back(p, N, cod_piatto + 1, cal + p[j].Kcal, vcurr);
		}
	}
}

void funzione(piatto* p, int N)
{
	char** s = malloc(3 * sizeof(char*));

	for (int i = 0; i < 3; i++)
		s[i] = malloc(20 * sizeof(char));

	Back(p, N, 1, 0, s);
}