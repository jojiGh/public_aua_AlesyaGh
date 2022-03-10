#include <stdio.h>

int main () {
	int character;

	printf("This program checks whether the entered character is from alphabet.\nPlease enter any character:\n");
	scanf("%c", &character);

	// in ASCII code, alphabet characters are from 65 to 90 and from 97 to 122
	if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122)) {
		printf("%c is an alphabet character.", character);
	} else {
		printf("%c is not an aplhabet character.", character);
	}

	return 0;
}
