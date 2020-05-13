extern void StazioniServizio(double m, int n, double *d, double *p);

int main()
{
	double d[] = { 260, 284, 308, 332, 356 };
	double p[] = { 35,35,33,29,23 };
	int n = sizeof(d) / sizeof(double);
	StazioniServizio(2020, n, d, p);
	return 0;
}