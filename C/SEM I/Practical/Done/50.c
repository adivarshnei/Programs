/* Write a program in C to display the index of smallest and largest element in 3 X 4 matrix of integers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int intArr;
typedef int loopVar;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		intArr arr[3][4];
		loopVar i, j;
		int small, large;
		int smallRowIndex, smallColmIndex;
		int largeRowIndex, largeColmIndex;

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				printf("Enter element (%d, %d): ", i, j);
				scanf("%d", & arr[i][j]);
			}
		}

		printf("Given matrix is: \n");

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				printf("%d\t", arr[i][j]);
			}

			printf("\n");
		}

		small = large = arr[0][0];
		smallRowIndex = smallColmIndex = 0;
		largeRowIndex = largeColmIndex = 0;

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				if (arr[i][j] < small) {
					smallRowIndex = i;
					smallColmIndex = j;

					small = arr[i][j];
				}

				if (arr[i][j] > large) {
					largeRowIndex = i;
					largeColmIndex = j;

					large = arr[i][j];
				}
			}
		}
		
		printf("\nThe largest element %d is at index (%d, %d)\n", arr[smallRowIndex][smallColmIndex], smallRowIndex, smallColmIndex);
		printf("The largest element %d is at index (%d, %d)", arr[largeRowIndex][largeColmIndex], largeRowIndex, largeColmIndex);

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