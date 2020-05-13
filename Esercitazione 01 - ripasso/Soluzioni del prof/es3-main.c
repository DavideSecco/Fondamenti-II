#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	char s[100]; // 99 caratteri + 0
	printf("Inserire una stringa: ");
	scanf("%s", s);

	// s[i] -> *(s + i)
	for (int i = 0; *(s + i) != 0; ++i) {
		if (*(s + i) >= 'a' && *(s + i) <= 'z') {
			// Il carattere corrente è una lettera minuscola
			//*(s + i) = *(s + i) - 32;
			*(s + i) = *(s + i) - ('a' - 'A');
		}
	}

	printf("%s", s);

	return EXIT_SUCCESS;
}