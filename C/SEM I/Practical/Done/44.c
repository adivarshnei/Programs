/* Write a program in C to print the following pattern:
					5
				5	4	5
			5	4	3	4	5	
		5	4	3	2	3	4	5
	5	4	3	2	1	2	3	4	5	*/

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
			for (j = n - 1; j > i; j--){
				printf("\t");
			}
			
			for (j = 0; j < i + 1; j++) {
				printf("%d\t", 6 - j - 1);
			}

			j--;

			for (; j >= 1; j--){
				printf("%d\t", 6 - j);
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