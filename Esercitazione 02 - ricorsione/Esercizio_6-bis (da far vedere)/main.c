#include <stdio.h>
#include <limits.h>

//non è perfetto, ci sono casi in cui non funziona, ma di base è ok

int divisione_negativi(int a, int b)
{
	if (/*a == 0 ||*/ b == 0)
		return INT_MAX;

	if (a == b)
		return 1;
	else if ((-a) == b || a == (-b))
		return -1;

	if((a*b)>0)
		return divisione_negativi(a - b, b) + 1;
	else
		return divisione_negativi(a + b, b) - 1;
}

int main()
{
	int a = -4;
	int b = -2;
	int ris = divisione_negativi(a, b);
	printf("%d : %d = %d", a, b, ris);
}