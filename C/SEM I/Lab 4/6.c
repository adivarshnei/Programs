/* Write a program to find gross salary of employee if DA is 40% of basic Salary and HRA is 20% of basic salary. Basic salary will be entered as input by keyboard. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef float salary;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		salary grossSal = 0, basicSal, daSal, hraSal;

		printf("Enter the basic salary of the employee: ");
		scanf("%f", & basicSal);

		daSal = (basicSal * 40) / 100;
		hraSal = (basicSal * 20) / 100;

		grossSal = basicSal + daSal + hraSal;

		printf("Basic Salary: %.2f\n", basicSal);
		printf("DA:           %.2f\n", daSal);
		printf("HRA:          %.2f\n", hraSal);
		printf("Gross Salary: %.2f\n", grossSal);

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