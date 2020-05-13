#include <stdio.h>
#include <string.h>

// potresti farlo creando un altra funzione con una variabile ausiliaria 

int minimo(int *vec, int len)
{	
	if (len == 1)
	{
		return vec[0];
	}
	
	int min = vec[0];

	if (minimo(vec + 1, len - 1 ) < min)
	{
		return minimo(vec+1, len-1);
	}
	else
		return min;
}

int main(void)
{
	int vec[] = {-1,0,3,-2,2,1,6,0};
	int size = sizeof(vec) / sizeof(vec[0]);
	int min = minimo(vec, size);
	printf("minimo: %d", min);
	return 0;
}