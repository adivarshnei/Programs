/* Write a program in C to print the following pattern:
	1	2	3
	1	2	3
	1	2	3	*/

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
				printf("%d\t", j + 1);
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