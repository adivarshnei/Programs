/* Write a program in C that accepts N * N matrix as input and print transpose of this matrix */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int intArr;
typedef int loopVar;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		intArr initA[50][50], transpA[50][50];
		loopVar i, j;
		int sizeA;

		printf("Enter matrix A size: ");
		scanf("%d", & sizeA);

		printf("Enter matrix A: \n");

		for (i = 0; i < sizeA; i++) {
			for (j = 0; j < sizeA; j++) {
				printf("Enter element (%d, %d): ", i, j);
				scanf("%d", & initA[i][j]);
			}
		}

		for (i = 0; i < sizeA; i++) {
			for (j = 0; j < sizeA; j++) {
				transpA[j][i] = initA[i][j];
			}
		}

		printf("\n Matrix A: \n");

		for (i = 0; i < sizeA; i++) {
			for (j = 0; j < sizeA; j++) {
				printf("%d\t", initA[i][j]);
			}

			printf("\n");
		}

		printf("\nTranspose of A: \n");

		for (i = 0; i < sizeA; i++) {
			for (j = 0; j < sizeA; j++) {
				printf("%d\t", transpA[i][j]);
			}

			printf("\n");
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