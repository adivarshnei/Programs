#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int intArr;
typedef int loopVal;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		intArr a[50][50], b[50][50], c[50][50];
		loopVal i, j;
		int rowSizeA, colSizeA;
		int rowSizeB, colSizeB;
		int choice;

		do {
			printf("\n1. Addition\n");
			printf("2. Subtraction\n");
			printf("3. Transpose\n");
			printf("4. Exit\n");
			printf("Enter Option: ");
			scanf("%d", & choice);

			switch (choice) {
				case 1:
				case 2:
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
								scanf("%d", & a[i][j]);
							}
						}

						printf("Enter matrix B: \n");

						for (i = 0; i < rowSizeB; i++) {
							for (j = 0; j < colSizeB; j++) {
								printf("Enter element (%d, %d): ", i, j);
								scanf("%d", & b[i][j]);
							}
						}

						for (i = 0; i < rowSizeA; i++) {
							for (j = 0; j < colSizeA; j++) {
								if (choice == 1) {
									c[i][j] = a[i][j] + b[i][j];
								} else if (choice == 2) {
									c[i][j] = a[i][j] - b[i][j];
								}
							}
						}

						printf("\nMatrix A: \n");

						for (i = 0; i < rowSizeA; i++) {
							for (j = 0; j < colSizeA; j++) {
								printf("%d\t", a[i][j]);
							}

							printf("\n");
						}

						printf("\nMatrix B: \n");

						for (i = 0; i < rowSizeA; i++) {
							for (j = 0; j < colSizeA; j++) {
								printf("%d\t", b[i][j]);
							}

							printf("\n");
						}

						printf("Resultant matrix C is: \n");

						for (i = 0; i < rowSizeA; i++) {
							for (j = 0; j < colSizeA; j++) {
								printf("%d\t", c[i][j]);
							}

							printf("\n");
						}

					} else {
						if (choice == 1) {
							printf("Matrix addition is not possible for matrices with unequal orders.");
						} else if (choice == 2) {
							printf("Matrix subtraction is not possible for matrices with unequal orders.");
						}
					}

					break;

				case 3:
					printf("Enter matrix A row size: ");
					scanf("%d", & rowSizeA);
					printf("Enter matrix A column size: ");
					scanf("%d", & colSizeA);

					printf("Enter matrix A: \n");

					for (i = 0; i < rowSizeA; i++) {
						for (j = 0; j < colSizeA; j++) {
							printf("Enter element (%d, %d): ", i, j);
							scanf("%d", & a[i][j]);
						}
					}

					for (i = 0; i < rowSizeA; i++) {
						for (j = 0; j < colSizeA; j++) {
							c[j][i] = a[i][j];
						}
					}

					printf("\nMatrix A: \n");

					for (i = 0; i < rowSizeA; i++) {
						for (j = 0; j < colSizeA; j++) {
							printf("%d\t", a[i][j]);
						}

						printf("\n");
					}

					printf("Resultant matrix C is: \n");

					for (i = 0; i < colSizeA; i++) {
						for (j = 0; j < rowSizeA; j++) {
							printf("%d\t", c[i][j]);
						}

						printf("\n");
					}

					break;

				case 4:
					choice = 1;
					break;

				default:
					printf("Wrong choice. Please enter again\n\n");

					getch();
					break;
			}

		}
		while (choice != 1 && choice != 2 && choice != 3);

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