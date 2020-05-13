#if !defined TORRECARTONI_H
#define TORRECARTONI_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
	unsigned p; //peso
	unsigned a; //altezza
	unsigned l; //Limite
}cartone;

extern void TorreCartoni(cartone *c, int n);

#endif /* TORRECARTONI_H */

