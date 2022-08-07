/* Write a program to add three numbers */

#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {

		int a, b, c, d;

		printf("Enter the first number: ");
		scanf("%d", & a);

		printf("Enter the second number: ");
		scanf("%d", & b);

		printf("Enter the third number: ");
		scanf("%d", & c);

		d = a + b + c;

		printf("The sum of %d, %d and %d is %d", a, b, c, d);

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