/* (a) Write a C program to check whether a triangle is Equilateral, scalene, or isosceles */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int side1, side2, side3, validChk;

		printf("Enter three sides of the triangle: ");
		scanf("%d%d%d", & side1, & side2, & side3);

		if (side1 > side2 && side1 > side3) {
			if (side2 + side3 <= side1) {
				validChk = 0;
			} else {
				validChk = 1;
			}
		} else if (side2 > side1 && side2 > side3) {
			if (side1 + side3 <= side2) {
				validChk = 0;
			} else {
				validChk = 1;
			}
		} else if (side3 > side1 && side3 > side2) {
			if (side1 + side2 <= side3) {
				validChk = 0;
			} else {
				validChk = 1;
			}
		}

		if (validChk == 0) {
			printf("The triangle is invalid\n");
		} else {
			if (side1 == side2 && side2 == side3) {
				printf("The triangle is equilateral\n");
			} else if (side1 == side2 || side2 == side3 || side1 == side3) {
				printf("The triangle is isoceles\n");
			} else {
				printf("The triangle is scalene\n");
			}
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