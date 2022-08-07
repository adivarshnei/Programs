/* Write a C program to check whether a character is an alphabet, digit or special character */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		char characEntered;

		printf("Enter the character to be checked: ");
		scanf(" %c", & characEntered);

		if (characEntered >= '1' && characEntered <= '9') {
			printf("The character %c is a digit\n", characEntered);
		} else if (tolower(characEntered) >= 'a' && tolower(characEntered) <= 'z') {
			printf("The character %c is an alphabet\n", characEntered);
		} else {
			printf("The character %c is a special character\n", characEntered);
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