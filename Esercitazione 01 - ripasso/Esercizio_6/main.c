#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//problema acquisizione stringhe con spazi

struct persona
{
	char nome[100];
	char cognome[100];
	struct data {
		size_t gg;
		size_t mm;
		size_t aa;
	};
	char luogo[100];
	char indirizzo[100];
	char CF[16];
};

int main()
{
	size_t n = 1; //numero di persone
	struct persona *p;
	p = malloc(n*sizeof(struct persona));
	
	for (size_t i = 0; i < n; i++)
	{
		printf("\ninserirsci tutte le generalità:\n nome e cognome:");
		scanf("%s %s", p[i].nome, p[i].cognome);
		printf("\ndata di nascita:");
		scanf("%d %d %d", &p[i].gg, &p[i].mm, &p[i].aa);
		printf("\nluogo, indirizzo e CF:");
		scanf("%s %s %s", p[i].luogo, p[i].indirizzo, p[i].CF);
	}

	FILE *f = fopen("file.txt", "w");

	for (size_t i = 0; i < n; i++)
	{
		printf("\n nome e cognome : %s %s", p[i].nome, p[i].cognome);
		fprintf(f, "\n nome e cognome : %s %s", p[i].nome, p[i].cognome);
		printf("\n data: %i / %i / %i", p[i].gg, p[i].mm, p[i].aa);
		fprintf(f,"\n data: %i / %i / %i", p[i].aa, p[i].mm, p[i].aa);
		printf("\nluogo, indirizzo e CF: \n%s \n %s \n %s", p[i].luogo, p[i].indirizzo, p[i].CF);
		fprintf(f,"\nluogo, indirizzo e CF:\n %s \n %s \n %s", p[i].luogo, p[i].indirizzo, p[i].CF);
	}
	fclose(f);
}


