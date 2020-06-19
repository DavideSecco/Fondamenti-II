void Back(int *v, int size, int i, int u)
{
	if (i >= u)
		return;

	int tmp = v[i];
	v[i] = v[u];
	v[u] = tmp;

	Back(v, size, i + 1, u - 1);
}


void Inverti(int *v, int v_size)
{
	Back(v, v_size, 0, v_size - 1);
}