/* Write a program to print all prime numbers <= a given number */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num;
		int i, j;
		int primeChk = 1;

		printf("Enter the number below which primes are to be printed: ");
		scanf("%d", & num);

		printf("\nList of Primes: ");

		for (i = 2; i <= num; i++) {
			primeChk = 1;

			for (j = 2; j < i; j++) {
				if (i % j == 0) {
					primeChk = 0;
				}
			}

			if (primeChk == 1) {
				printf("%d\t", i);
			}
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