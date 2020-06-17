#include "newton.h"

double f(const polinomio *p, double x)
{
	double y = 0;
	for (size_t i = 0; i < p->size; i++)
	{
		y = y + p->coeffs[i] * pow(x, i);
	}
	return y;
}

double f_der(const polinomio *d, double x)
{
	double y = 0;
	for (size_t i = 0; i < d->size; i++)
	{
		y = y + d->coeffs[i] * pow(x, i);
	}
	return y;
}

double back(const polinomio *p, const polinomio *d, double xn, double t, int* max_iter)
{
	double x1 = xn - (f(p, xn) / f_der(d, xn));

	if (fabs(x1 - xn) < t)
		return x1;

	*max_iter = *max_iter - 1;

	if (*max_iter == 0)
		return x1;

	return back(p, d, x1, t, max_iter);
}

double Newton(const polinomio *p, const polinomio *d, double xn, double t, int max_iter)
{
	if (max_iter <= 0)
		max_iter = 10000000;

	double y = back(p, d, xn, t, &max_iter);
	return y;
}