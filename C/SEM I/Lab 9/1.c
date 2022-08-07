/* Write a program in C to find the index of the smallest and largest element of a 10 element array */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int intArr;
typedef int loopVar;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		intArr a[10];
		loopVar i;
		int small, large;
		int smallIndex, largeIndex;

		for (i = 0; i < 10; i++) {
			printf("Enter element: ");
			scanf("%d", & a[i]);
		}

		printf("Given array is: ");

		for (i = 0; i < 10; i++) {
			printf("%d\t", a[i]);
		}

		small = large = a[0];
		smallIndex = largeIndex = 0;

		for (i = 0; i < 10; i++) {
			if (a[i] < small) {
				smallIndex = i;
				small = a[i];
			}

			if (a[i] > large) {
				largeIndex = i;
				large = a[i];
			}
		}

		printf("\n\nThe smallest element %d is at index %d\n", a[smallIndex], smallIndex);
		printf("The largest element %d is at index %d", a[largeIndex], largeIndex);

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