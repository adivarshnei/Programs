/* Write a program in C to accept an integer numbers and to check whether it is a perfect number */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num, i, sum = 0;

		printf("Enter the number to be checked: ");
		scanf("%d", & num);

		printf("%d has factors: ", num);

		for (i = 1; i < num; i++) {
			if (num % i == 0) {
				sum += i;
				printf("%d\t", i);
			}
		}

		printf("\n1");

		for (i = 2; i < num; i++) {
			if (num % i == 0) {
				printf(" + %d", i);
			}
		}

		printf(" = %d", sum);

		if (sum == num) {
			printf(" = %d", num);
			printf("\n%d is a perfect number\n", num);
		} else {
			printf(" != %d", num);
			printf("\n%d is not a perfect number\n", num);
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