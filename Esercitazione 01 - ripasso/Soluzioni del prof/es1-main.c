#include <stdlib.h>
#include <stdio.h>

// char **argv
int main(int argc, char *argv[]) {
	
	if (argc != 4) {
		fprintf(stderr, "ERRORE: il numero dei parametri non e' corretto.");
		return EXIT_FAILURE;
	}
	
	char *s = argv[1]; // Stringa
	char c1 = argv[2][0]; // Carattere 1
	char c2 = argv[3][0]; // Carattere 2

	size_t cnt1 = 0, cnt2 = 0;

	for (int i = 0; s[i] != 0; ++i) {
		if (c1 == s[i]) {
			cnt1++;
		}
		if (c2 == s[i]) {
			cnt2++;
		}
	}

	if (cnt1 > cnt2) {
		printf("%c", c1);
	}
	else {
		printf("%c", c2);
	}


	return EXIT_SUCCESS;
}