#include "torrecartoni.h"

int main()
{
	cartone c[] = { {.p = 9,.a = 3,.l = 5}, {.p = 10,.a = 10,.l = 8}, {.p = 10,.a = 20,.l = 40}  };
	int n = sizeof(c) / sizeof(cartone);
	TorreCartoni(c, n);
	return 0;
}