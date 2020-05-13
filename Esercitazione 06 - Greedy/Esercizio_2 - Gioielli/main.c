#include "gioielli.h"

int main()
{
	int *ret_size=malloc(0);
	Gioiello *g = Gioielli("gioielli_2.txt", 121, ret_size);
	printf("finito");
	return 0;
}