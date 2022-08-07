/* Write a C program a program to check whether an alphabet is a vowel or consonant */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		char alphEntered;

		printf("Enter the alphabet to be checked: ");
		scanf(" %c", & alphEntered);

		if (tolower(alphEntered) == 'a' || tolower(alphEntered) == 'e' || tolower(alphEntered) == 'i' || tolower(alphEntered) == 'o' || tolower(alphEntered) == 'u') {
			printf("The alphabet %c is a vowel\n", alphEntered);
		} else if (isalpha(alphEntered)) {
			printf("The alphabet %c is a consonant\n", alphEntered);
		} else {
			printf("The character %c is not an alphabet\n", alphEntered);
		}

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

		count++;

		if (count >= 50) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		}

	}

	printf("Normal END\n");

	getch();
	return 0;
}