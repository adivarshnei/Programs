/* Write a C program to convert a given integer (in days) to years, weeks and days */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int raw, y, w, d;

		printf("Enter the total days: ");
		scanf("%d", & raw);

		y = raw / 365;
		w = (raw - (365 * y)) / 7;
		d = (raw - (365 * y) - (w * 7));

		printf("%d days is %d years, %d weeks and %d days", raw, y, w, d);

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