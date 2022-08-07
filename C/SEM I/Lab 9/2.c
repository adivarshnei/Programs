/* Write a program in C to find the index of the smallest and largest element of a 4 X 4 element matrix */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int intArr;
typedef int loopVar;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		intArr a[4][4];
		loopVar i, j;
		int small, large;
		int smallRowIndex, smallColmIndex;
		int largeRowIndex, largeColmIndex;

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				printf("Enter element: ");
				scanf("%d", & a[i][j]);
			}
		}

		printf("Given matrix is:\n");

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				printf("%d\t", a[i][j]);
			}

			printf("\n");
		}

		small = large = a[0][0];
		smallRowIndex = smallColmIndex = 0;
		largeRowIndex = largeColmIndex = 0;

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (a[i][j] < small) {
					smallRowIndex = i;
					smallColmIndex = j;

					small = a[i][j];
				}

				if (a[i][j] > large) {
					largeRowIndex = i;
					largeColmIndex = j;

					large = a[i][j];
				}
			}
		}

		printf("The smallest element %d is at index (%d, %d)\n", a[smallRowIndex][smallColmIndex], smallRowIndex, smallColmIndex);
		printf("The largest element %d is at index (%d, %d)", a[largeRowIndex][largeColmIndex], largeRowIndex, largeColmIndex);

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