/* Write a C program to print a block F using hash (#), where the F has a height of six characters and width of five and four characters */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		printf("#####\n");
		printf("#\n");
		printf("####\n");
		printf("#\n");
		printf("#\n");
		printf("#\n");

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