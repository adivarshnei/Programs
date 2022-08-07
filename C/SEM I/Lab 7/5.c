/* Write a program to print the following pattern in C:
	3	3	3
	2	2	2
	1	1	1	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int n;
		int i, j;

		printf("Enter the number of rows: ");
		scanf("%d", & n);

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%d\t", n - i);
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