/* Write a program to accept two matrices of some order. (Order must be given by user) find out the sum of these matrices and print the sum of matrices. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int intArr;
typedef int loopVar;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		intArr matrixA[50][50], matrixB[50][50], matrixC[50][50];
		loopVar i, j;
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

		if (rowSizeA == rowSizeB && colSizeA == colSizeB) {
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

			for (i = 0; i < rowSizeA; i++) {
				for (j = 0; j < colSizeA; j++) {
					matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
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

			for (i = 0; i < rowSizeA; i++) {
				for (j = 0; j < colSizeA; j++) {
					printf("%d\t", matrixB[i][j]);
				}

				printf("\n");
			}

			printf("Resultant matrix C is: \n");

			for (i = 0; i < rowSizeA; i++) {
				for (j = 0; j < colSizeA; j++) {
					printf("%d\t", matrixC[i][j]);
				}

				printf("\n");
			}

		} else {
			printf("Matrix addition is not possible for matrices with unequal orders.");
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