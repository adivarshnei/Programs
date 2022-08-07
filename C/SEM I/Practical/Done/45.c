/*	Write a program in C to print the following pattern:
	1
	0	1
	1	0	1	
	0	1	0	1
	1	0	1	0	1	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int n;
		int i, j;
		int num = 1;

		printf("Enter the number of rows: ");
		scanf("%d", & n);

		for (i = 0; i < n; i++) {
			if (i % 2 == 0) {
				num = 1;
			} else {
				num = 0;
			}

			for (j = 0; j < i + 1; j++) {
				if (num % 2 != 0) {
					printf("%d\t", num);
					num--;
				} else {
					printf("%d\t", num);
					num++;
				}
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