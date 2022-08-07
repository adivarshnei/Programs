/* Write a program to convert a decimal number into a binary number */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef int intArr;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int dec, temp;
		intArr bin[50];
		int i, j;

		printf("Enter the decimal number: ");
		scanf("%d", & dec);

		temp = dec;

		for (i = 0; temp > 0; i++) {
			bin[i] = temp % 2;
			temp /= 2;
		}

		printf("Decimal %d = Binary ", dec);

		for (j = i - 1; j >= 0; j--) {
			printf("%d", bin[j]);
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