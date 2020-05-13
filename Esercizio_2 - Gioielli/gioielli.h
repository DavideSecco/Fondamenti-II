#define _CRT_SECURE_NO_WARNINGS

#if !defined GIOIELLI_H
#define GIOLELLI_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int codice;
	float peso;
	float prezzo;
}Gioiello;

Gioiello* Gioielli(const char* filename, float b, int *ret_size);

#endif //GIOIELLI_H

