#include <stdlib.h>void BackTracking(int n, size_t* e){	*e = *e + 1;	if (n == 1) {		printf("%d", n);		return;	}	printf("%d, ", n);		if (n % 2 == 0)		BackTracking(n / 2, e);	else		BackTracking(3 * n + 1, e);}size_t Hailstone(int n){	if (n <= 0)		return 0;	size_t Elementi = 0;	BackTracking(n, &Elementi);	return Elementi;}
int main()
{
	int n = 0;
	Hailstone(n);
	return 0;
}