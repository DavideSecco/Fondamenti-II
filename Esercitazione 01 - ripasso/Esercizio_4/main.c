#include <stdio.h>

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		int cifra = atoi(argv[i]);
		printf("\n%d: ", cifra);
		int minuti = cifra / 60000;
		int temp = cifra % 60000;
		int secondi = temp / 1000;
		temp = cifra % 1000;
		int millisecondi = temp;
		printf(" tempo %i: %d minuti %d secondi %d millisecondi\n", i, minuti, secondi, millisecondi);
	}
	return 0;
}
