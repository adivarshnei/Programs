/* Write a program to check a number whether it is prime number or not */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num, i, primeChk = 0;

		printf("Enter the number to be checked: ");
		scanf("%d", & num);

		if (num != 1) {
			for (i = 2; i < num; i++) {
				if (num % i == 0) {
					primeChk = 1;
					break;
				}
			}

			if (primeChk == 0) {
				printf("%d is prime", num);
			} else if (primeChk == 1) {
				printf("%d is composite\n", num);
				printf("Its factors are: ");

				for (i = 1; i < num; i++) {
					if (num % i == 0) {
						printf("%d\t", i);
					}
				}
			}
		} else {
			printf("%d is neither prime nor composite", num);
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