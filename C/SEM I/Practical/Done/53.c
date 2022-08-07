/* Write a program to find out the product/Multiplication of two matrices and print the product matrix.(order of matrices must be given by user) */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int intArr;
typedef int loopVal;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		intArr matrixA[50][50], matrixB[50][50], matrixC[50][50];
		loopVal i, j, k;
		int rowSizeA, colSizeA;
		int rowSizeB, colSizeB;

		printf("Enter matrix A row size: ");
		scanf("%d", & rowSizeA);
		printf("Enter matrix A column size: ");
		scanf("%d", & colSizeA);

		printf("Enter matrix B row size: ");
		scanf("%d", & rowSizeB);
		printf("Enter matrix B column size: ");
		scanf("%d", & colSizeB);

		if (rowSizeA == colSizeB) {
			for (i = 0; i < 50; i++) {
				for (j = 0; j < 50; j++) {
					matrixA[i][j] = 0;
					matrixB[i][j] = 0;
					matrixC[i][j] = 0;
				}
			}

			printf("Enter matrix A: \n");

			for (i = 0; i < rowSizeA; i++) {
				for (j = 0; j < colSizeA; j++) {
					printf("Enter element (%d, %d): ", i, j);
					scanf("%d", & matrixA[i][j]);
				}
			}

			printf("Enter matrix B: \n");

			for (i = 0; i < rowSizeB; i++) {
				for (j = 0; j < colSizeB; j++) {
					printf("Enter element (%d, %d): ", i, j);
					scanf("%d", & matrixB[i][j]);
				}
			}

			for (i = 0; i < 50; i++) {
				for (j = 0; j < 50; j++) {
					for (k = 0; k < 50; k++) {
						matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
					}
				}
			}

			printf("\nMatrix A: \n");

			for (i = 0; i < rowSizeA; i++) {
				for (j = 0; j < colSizeA; j++) {
					printf("%d\t", matrixA[i][j]);
				}

				printf("\n");
			}

			printf("\nMatrix B: \n");

			for (i = 0; i < rowSizeB; i++) {
				for (j = 0; j < colSizeB; j++) {
					printf("%d\t", matrixB[i][j]);
				}

				printf("\n");
			}

			printf("Resultant matrix C is: \n");

			for (i = 0; i < rowSizeA; i++) {
				for (j = 0; j < colSizeB; j++) {
					printf("%d\t", matrixC[i][j]);
				}

				printf("\n");
			}

		} else {
			printf("Matrix multplication is not possible for given matrices.");
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