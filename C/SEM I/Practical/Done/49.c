/* Write a program in C to display the index of smallest and largest element in 10 integers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int intArr;
typedef int loopVar;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		intArr arr[10];
		loopVar i;
		int small, large;
		int smallIndex, largeIndex;

		for (i = 0; i < 10; i++) {
			printf("Enter element (%d): ", i);
			scanf("%d", & arr[i]);
		}

		printf("Given array is: ");

		for (i = 0; i < 10; i++) {
			printf("%d\t", arr[i]);
		}

		small = large = arr[0];
		smallIndex = largeIndex = 0;

		for (i = 0; i < 10; i++) {
			if (arr[i] < small) {
				smallIndex = i;
				small = arr[i];
			}

			if (arr[i] > large) {
				largeIndex = i;
				large = arr[i];
			}
		}

		printf("\nThe smallest element %d is at index %d\n", arr[smallIndex], smallIndex);
		printf("The largest element %d is at index %d", arr[largeIndex], largeIndex);

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