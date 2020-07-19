#include "piatto.h"

extern funzione(piatto* p, int N);

int main() {
	piatto p[] = { {1, 300, "ciao",}, {2, 300, "ciao2",}, {3, 100, "ciao3",} };
	funzione(p, 3);
	return 0;
}