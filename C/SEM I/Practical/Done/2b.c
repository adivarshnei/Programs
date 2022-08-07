/* Write a program to calculate simple interest */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float princ, rate, time, interest;

		printf("Enter the principal amount: ");
		scanf("%f", & princ);
		printf("Enter the rate: ");
		scanf("%f", & rate);
		printf("Enter the time: ");
		scanf("%f", & time);

		interest = (princ * rate * time) / 100;

		printf("The simple interest is: %.2f", interest);

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