/* A library charges a fine for every book returned late.  For first 5 days the fine is 50 paisa, for 6-10 days, fine is one rupee and above 10 days, fine is 5 rupees.  If you return the book after 30 days your membership will be cancelled.  Write a program to accept the number of days the member is late to return the book and display the fine or appropriate message. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		unsigned int days;
		float totalFine = 0;

		printf("Enter the days the book was late by: ");
		scanf("%d", & days);

		if (days <= 5) {
			totalFine += (days * 0.50);
		} else if (days >= 6 && days <= 10) {
			totalFine += (5 * 0.50) + ((days - 5) * 1);
		} else if (days > 10) {
			totalFine += (5 * 0.50) + (5 * 1) + ((days - 10) * 5);
		}

		if (days < 30) {
			printf("\nThe book was returned %d days late.\nFines due: %.2f\n", days, totalFine);
		} else {
			printf("\nThe book was returned %d days late.\nFines due: %.2f\n", days, totalFine);
			printf("Due to the book being returned atleast 30 days after the deadline, your membership has been cancelled.\n");
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