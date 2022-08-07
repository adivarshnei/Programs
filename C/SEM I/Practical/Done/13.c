/* Write a program to calculate roots of a quadratic equation */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float varA, varB, varC, discr, rootAlpha, rootBeta, realRoot, imRoot;

		printf("Let the quadratic equation be ax^2 + bx + c = 0\n");

		do {
			printf("Enter the variable a: ");
			scanf("%f", & varA);
			printf("Enter the variable b: ");
			scanf("%f", & varB);
			printf("Enter the variable c: ");
			scanf("%f", & varC);

			if (varA == 0) {
				printf("The entered equation is not quadratic\n");
			}

		} while (varA == 0);

		printf("The equation is: %.2fx^2 + %.2fx + %.2f\n", varA, varB, varC);

		discr = pow(varB, 2) - 4 * varA * varC;

		if (discr > 0) {
			rootAlpha = ((-1) * varB + sqrt(discr)) / (2 * varA);
			rootBeta = ((-1) * varB - sqrt(discr)) / (2 * varA);

			printf("The roots of the equation is %.2f and %.2f\n", rootAlpha, rootBeta);
		} else if (discr == 0) {
			rootAlpha = ((-1) * varB) / (2 * varA);

			printf("The root of the equation is %.2f\n", rootAlpha);
		} else if (discr < 0) {
			realRoot = ((-1) * varB) / (2 * varA);
			imRoot = (sqrt(abs(discr))) / (2 * varA);

			printf("The roots of the equation is %.2f + (%.2f)i and %.2f - (%.2f)i\n", realRoot, imRoot, realRoot, imRoot);
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