/* Write a C program to convert a given integer (in seconds) to hours, minutes and seconds */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		unsigned int raw, h, m, s;

		printf("Enter the total seconds: ");
		scanf("%d", & raw);

		h = raw / 3600;
		m = (raw - (3600 * h)) / 60;
		s = (raw - (3600 * h) - (m * 60));

		printf("%d seconds is %d:%d:%d", raw, h, m, s);

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