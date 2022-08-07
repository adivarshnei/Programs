/* Write a C program to covert temperature from Fahrenheit to Celsius and Celsius to Fahrenheit (User must provide the choice of type of temperature) */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float tempInitl, tempFinal;
		char unit;

		printf("Enter the temperature to be converted: ");
		scanf("%f", & tempInitl);

		do {
			printf("Enter the unit to be converted to (C/F): ");
			scanf(" %c", & unit);

			if (tolower(unit) != 'f' && tolower(unit) != 'c') {
				printf("Invalid entry\n");
			}
		} while (tolower(unit) == 'f' && tolower(unit) == 'c');

		if (tolower(unit) == 'f') {
			tempFinal = ((tempInitl * 9) + 32 * 5) / 5;

			printf("%.2f C = %.2f F", tempInitl, tempFinal);
		} else if (tolower(unit) == 'c') {
			tempFinal = ((tempInitl * 5) - 32 * 5) / 9;

			printf("%.2f F = %.2f C", tempInitl, tempFinal);
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