/* Write a program to add three numbers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {

		int var1, var2, var3, sum;

		printf("Enter the three numbers: ");
		scanf("%d%d%d", & var1, & var2, & var3);

		sum = var1 + var2 + var3;

		printf("The sum of %d, %d and %d is %d", var1, var2, var3, sum);

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