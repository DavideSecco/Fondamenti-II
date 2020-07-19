#include "colora.h"



int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {
	int t = strlen(c);
	
	if (c_size <= 1 || t <= 1) {
		printf("NON CI SONO SOLUZIONI");
		return 0;
	}

	Back(m, c, c_size);

	return 1;
}