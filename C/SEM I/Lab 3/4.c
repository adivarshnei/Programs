/* Write a C program to check whether a triangle is right angled, obtuse or acute */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int angA, angB, angC;

		printf("Enter two angles (in degrees): ");
		scanf("%d%d", & angA, & angB);

		if (angA + angB >= 180) {
			printf("The triangle is invalid");
		} else {
			angC = 180 - (angA + angB);
			printf("The third angle is: %d\n", angC);

			if (angA == 90 || angB == 90 || angC == 90) {
				printf("The triangle is right\n");
			} else if (angA >= 90 || angB >= 90 || angC >= 90) {
				printf("The triangle is obtuse\n");
			} else {
				printf("The triangle is acute\n");
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