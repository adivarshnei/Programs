/* Write a C program to swap two values using functions */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(float, float);

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float a1, a2;

		printf("Enter the two variables: ");
		scanf("%f%f", & a1, & a2);

		printf("Unswapped Numbers: %.2f, %.2f \n", a1, a2);

		swap(a1, a2);

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

		count++;

		if (count >= 50) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		} //if (count >= 50) 

	} //while (rep == 1)

	printf("Normal END\n");

	getch();
	return 0;
} //int main(void) 

void swap(float a1, float a2) {
	float a3;

	a3 = a1;
	a1 = a2;
	a2 = a3;

	printf("Swapped Numbers: %.2f, %.2f ", a1, a2);
} //void swap(float a1, float a2)