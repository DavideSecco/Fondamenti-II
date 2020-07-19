#include <string.h>
#include <stdlib.h> 
#include <math.h>

int Back(const char* str, int len, int i) {
	int c = str[i] - 48;
	
	if (i == len - 1)
		return c* pow(10, len - i - 1);
		
	int numero = c*pow(10, len - i -1);
	return numero + Back(str, len, i + 1);
}

int AToI(const char* str) {
	
	if (str == NULL)
		return 0;

	int len = strlen(str);
	int som = Back(str, len, 0);
	return som;
}