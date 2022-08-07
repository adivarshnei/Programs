/* Write a program to accept a coordinate point in a XY coordinate system and determine in which quadrant the coordinate point lies */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float coordX, coordY;

		printf("Enter the abscissa of the coordinate: ");
		scanf("%f", & coordX);
		printf("Enter the ordinate of the coordinate: ");
		scanf("%f", & coordY);

		if (coordX > 0 && coordY > 0) {
			printf("The point (%.2f, %.2f) is in the first quadrant\n", coordX, coordY);
		} else if (coordX < 0 && coordY > 0) {
			printf("The point (%.2f, %.2f) is in the second quadrant\n", coordX, coordY);
		} else if (coordX < 0 && coordY < 0) {
			printf("The point (%.2f, %.2f) is in the third quadrant\n", coordX, coordY);
		} else if (coordX > 0 && coordY < 0) {
			printf("The point (%.2f, %.2f) is in the fourth quadrant\n", coordX, coordY);
		} else if (coordX == 0 && coordY > 0) {
			printf("The point (%.2f, %.2f) is on the Y axis above the origin\n", coordX, coordY);
		} else if (coordX == 0 && coordY < 0) {
			printf("The point (%.2f, %.2f) is on the Y axis below the origin\n", coordX, coordY);
		} else if (coordX > 0 && coordY == 0) {
			printf("The point (%.2f, %.2f) is on the X axis right to the origin\n", coordX, coordY);
		} else if (coordX < 0 && coordY == 0) {
			printf("The point (%.2f, %.2f) is on the X axis left to the origin\n", coordX, coordY);
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