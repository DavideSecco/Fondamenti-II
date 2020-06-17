#include "secanti.h"



double f(const polinomio* p, double x)
{
	double y = 0;
	for (size_t i = 0; i < p->size; i++)
	{
		y = y + p->coeffs[i] * pow(x, i);
	}
	return y;
}

double Back(const polinomio *p, double x0, double x1, double t, int* max_iter)
{
	double x2 = x1 - ((x1 - x0) / (f(p, x1) - f(p, x0))) * f(p, x1);
	
	*max_iter = *max_iter - 1;

	if (*max_iter == 0)
		return x2;	

	if (fabs(x2 - x1) <= t)
		return x2;

	return Back(p, x1, x2, t, max_iter);
}

double Secanti(const polinomio *p, double x0, double x1, double t, int max_iter)
{
	if (fabs(x1 - x0) < t)
		return x1;

	if (max_iter <= 0)
		max_iter = 1000000000;

	return Back(p, x0, x1, t, &max_iter);
}

int main()
{
	polinomio* p = malloc(sizeof(polinomio));
	p->size = 2;
	p->coeffs = malloc(p->size*sizeof(int));
	p->coeffs[0] = 1;
	p->coeffs[1] = -12;
	p->coeffs[2] = -3;
	p->coeffs[3] = 2;
	
	const double y = f(p, 3);
	Secanti(p, -2.00, 4.00, 0.0000100000, 4);
	return 0;
}