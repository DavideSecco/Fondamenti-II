#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
	FILE *f = fopen("file.txt", "r");
	char str[100];
	size_t cont = 0;
	scanf("%s", str);
	
	//si può fare molto più semplice (video)
	while (1)
	{
		char c = fgetc(f);

		if (c == EOF)
			break;

		if (c == str[0])
		{
			fseek(f, -1, SEEK_CUR);
			char str2[100];
			fgets(str2, strlen(str)+1, f);
			if (strcmp(str, str2) == 0)
				cont++;
		}
	}
	fclose(f);
	printf("ris: %i", cont);
	return 0;
}