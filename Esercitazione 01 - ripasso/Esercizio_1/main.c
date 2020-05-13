#include <stdio.h>

main(int argc, char *argv[])
{
	int i = 0;
	size_t cont_1 = 0;
	size_t cont_2 = 0;
	while (1)
	{
		if (argv[1][i] == argv[2][0])
			cont_1++;
		if (argv[1][i] == argv[3][0])
			cont_2++;
		if (argv[1][i] == '\0')
			break;
		i++;
	}

	if(cont_1 > cont_2)
		printf("\nil maggiore e' : %c", argv[2][0]);
	else if(cont_1 < cont_2)
		printf("\nil maggiore e' : %c", argv[3][0]);
}