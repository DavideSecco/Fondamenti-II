#include <stdio.h>
#include <math.h>


int ProdottoNegativi(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	
	if (b == 1)
		return a;
	else if (b == -1)
		return -a;
	
	if (b > 0)
		return a + ProdottoNegativi(a, b - 1);
	else
		return  - a + ProdottoNegativi(a, b + 1);
}

int main()
{
	int a = 3;
	int b = 4;
	int prod = ProdottoNegativi(a, b);
	printf(" %d * %d = %d\n",a, b, prod);
	return 0;
}