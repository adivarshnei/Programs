/* Write a program in C to implement Simple Calculator */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float var1, var2;
		double result, oppResult;
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
			printf("5. Exponent\n");
			printf("6. All operations\n");
			printf("Enter the operation: ");
			scanf("%d", & opChoice);

			switch (opChoice) {
				case 1:
					result = var1 + var2;

					printf("%.2f + %.2f = %.2f\n", var1, var2, result);

					validChk = 1;
					break;

				case 2:
					result = var1 - var2;
					oppResult = var2 - var1;

					printf("%.2f - %.2f = %.2f\n", var1, var2, result);
					printf("%.2f - %.2f = %.2f\n", var2, var1, oppResult);

					validChk = 1;
					break;

				case 3:
					result = var1 * var2;

					printf("%.2f * %.2f = %.2f\n", var1, var2, result);

					validChk = 1;
					break;

				case 4:
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
					}

					validChk = 1;
					break;

				case 5:
					if (var1 == 0 && var2 == 0) {
						printf("Invalid operation for entered values\n");
					} else {
						result = pow(var1, var2);
						oppResult = pow(var2, var1);

						printf("%.2f ^ %.2f = %.2f\n", var1, var2, result);
						printf("%.2f ^ %.2f = %.2f\n", var2, var1, oppResult);
					}

					validChk = 1;
					break;

				case 6:
					result = var1 + var2;

					printf("%.2f + %.2f = %.2f\n", var1, var2, result);

					getch();

					result = var1 - var2;
					oppResult = var2 - var1;

					printf("%.2f - %.2f = %.2f\n", var1, var2, result);
					printf("%.2f - %.2f = %.2f\n", var2, var1, oppResult);

					getch();

					result = var1 * var2;

					printf("%.2f * %.2f = %.2f\n", var1, var2, result);

					getch();

					if (var1 == 0 && var2 == 0) {
						printf("");
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
					}

					getch();

					if (var1 == 0 && var2 == 0) {
						printf("");
					} else {
						result = pow(var1, var2);
						oppResult = pow(var2, var1);

						printf("%.2f ^ %.2f = %.2f\n", var1, var2, result);
						printf("%.2f ^ %.2f = %.2f\n", var2, var1, oppResult);
					}

					validChk == 1;

					break;

				default:
					printf("\nWrong Choice\n");
					validChk = 0;
					break;
			}
		} while (validChk == 0);

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