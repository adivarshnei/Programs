/* Write a program to convert a binary number into a decimal number */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int dec = 0, temp, bin;
		int i;

		printf("Enter the binary number: ");
		scanf("%d", & bin);

		temp = bin;
		i = 1;

		for (; temp > 0;) {
			dec += (temp % 10) * i;
			temp /= 10;
			i *= 2;
		}

		printf("Binary %d = Decimal %d ", bin, dec);

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