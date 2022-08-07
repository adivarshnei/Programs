/* Write a program to find the sum of the following series:
-1^3 + 3^3 - 5^3 + 7^3 - 9^3 ... up to n terms */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float sum = 0, term;
		int n;
		int i;

		printf("Enter the number of terms upto which sum is to be calculated: ");
		scanf("%d", & n);

		printf("- ");

		for (i = 1; i <= n; i++) {
			term = pow(-1.0, i) * pow((2*i-1), 3.0);
			sum += term;

			printf("%.0f", fabs(term));

			if (i != n) {
				if (pow(-1.0, i+1) * pow((2*(i+1)-1), 3.0) > 0) {
					printf(" + ");
				} else {
					printf(" - ");
				}
			}
		}

		printf("\n= %.0f", sum);

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