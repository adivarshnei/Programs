/* Write a C program to implement simple calculator (Addition, Subtraction, Multiplication, Division) using the concept of functions */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int addn(float, float);
int subt(float, float);
int mult(float, float);
int divs(float, float);

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float var1, var2;
		int opChoice, validChk;

		printf("Enter the variable a: ");
		scanf("%f", & var1);

		printf("Enter the variable b: ");
		scanf("%f", & var2);

		do {
			printf("1. Addition\n");
			printf("2. Subtractiion\n");
			printf("3. Multiplication\n");
			printf("4. Division\n");
			printf("5. All operations\n");
			printf("Enter the operation: ");
			scanf("%d", & opChoice);

			switch (opChoice) {
				case 1:
					validChk = addn(var1, var2);
					break;

				case 2:
					validChk = subt(var1, var2);
					break;

				case 3:
					validChk = mult(var1, var2);
					break;

				case 4:
					validChk = divs(var1, var2);
					break;

				case 5:
					validChk = addn(var1, var2);
					getch();

					validChk = subt(var1, var2);
					getch();

					validChk = mult(var1, var2);
					getch();

					validChk = divs(var1, var2);
					getch();

					break;

				default:
					printf("\nWrong Choice\n");
					validChk = 0;
					break;
			} //switch (opChoice) 

		} while (validChk == 0);

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

int addn(float var1, float var2) {
	double result;

	result = var1 + var2;

	printf("%.2f + %.2f = %.2f\n", var1, var2, result);

	return 1;
} //int addn(float var1, float var2)

int subt(float var1, float var2) {
	double result, oppResult;

	result = var1 - var2;
	oppResult = var2 - var1;

	printf("%.2f - %.2f = %.2f\n", var1, var2, result);
	printf("%.2f - %.2f = %.2f\n", var2, var1, oppResult);

	return 1;
} //int subt(float var1, float var2)

int mult(float var1, float var2) {
	double result, oppResult;

	result = var1 * var2;

	printf("%.2f * %.2f = %.2f\n", var1, var2, result);
} //int mult(float var1, float var2) 

int divs(float var1, float var2) {
	double result, oppResult;

	if (var1 == 0 && var2 == 0) {
		printf("Invalid operation for entered values\n");
	} else if (var1 == 0) {
		result = var1 / var2;

		printf("%.2f / %.2f = %.2f\n", var1, var2, result);
	} else if (var2 == 0) {
		oppResult = var2 / var1;

		printf("%.2f / %.2f = %.2f\n", var2, var1, oppResult);
	} else {
		result = var1 / var2;
		oppResult = var2 / var1;

		printf("%.2f / %.2f = %.2f\n", var1, var2, result);
		printf("%.2f / %.2f = %.2f\n", var2, var1, oppResult);
	} //End of extended if clause

	return 1;
} //int divs(float var1, float var2)