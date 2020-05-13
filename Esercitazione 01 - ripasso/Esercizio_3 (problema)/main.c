#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
//problema acquisizione stringa
main()
{
	char str[100]; //si si fa così
	scanf("%s", str);
	int i = 0;
	while (1)
	{
		char l1 = *(str + i);
		if ( l1 == 0)
			return 0;
		char l2 = toupper(l1);
		printf("%c", l2);
		i++;
	}
	return 0;
}