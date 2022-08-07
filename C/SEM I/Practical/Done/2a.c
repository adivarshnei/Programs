/* Write a program find area of a circle */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define PI 3.14

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {

		float r;
		float area;

		printf("Enter the radius: ");
		scanf("%f", & r);

		area = PI * r * r;

		printf("The area of circle is %.2f", area);

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