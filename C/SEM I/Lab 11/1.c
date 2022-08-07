/* Write a program in C to print fibonacci series using recursive functions */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef unsigned int loopVar;

int fibRec(int);
int fibNotRec(int);

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num, choice;
		loopVar i;

		printf("Enter number of terms: ");
		scanf("%d", & num);

		scanf("%d", & choice);

		switch (choice) {
			case 1:
				for (i = 0; i < num; i++) {
					if (i == num - 1) {
						printf("%d", fibRec(i));
					} else {
						printf("%d, ", fibRec(i));
					} //End of extended if clause
				} //for (i = 0; i < num; i++)

				break;

			case 2:
				for (i = 0; i < num; i++) {
					if (i == num - 1) {
						printf("%d", fibNotRec(i));
					} else {
						printf("%d, ", fibNotRec(i));
					} //End of extended if clause
				} //for (i = 0; i < num; i++)

				break;
		} //switch (choice) 

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

		count++;

		if (count >= 50) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		} //if (count >= 50) 

	} //while (rep == 1) 

	printf("Normal END\n");

	getch();
	return 0;
} //int main(void)

int fibRec(int n) {
	if (n == 0 || n == 1) {
		return n;
	} else {
		return fibRec(n - 1) + fibRec(n - 2);
	} //End of extended if clause
} //int fibRec(int n)

int fibNotRec(int n) {
	loopVar i;
	int t1 = 0, t2 = 1, term;

	for (i = 0; i < n + 1; i++) {
		if (i <= 1) {
			term = i;
		} else {
			term = t1 + t2;
			t1 = t2;
			t2 = term;
		} //End of extended if clause
	} //for (i = 0; i < n + 1; i++) 

	return term;
} //int fibNotRec(int n)