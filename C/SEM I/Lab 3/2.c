/* Write a program to check whether a given year is leap year or not */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int year, leapCheck;

		printf("Enter the year to be checked: ");
		scanf("%d", & year);

		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0) {
					leapCheck = 1;
				} else {
					leapCheck = 0;
				}
			} else {
				leapCheck = 1;
			}
		} else {
			leapCheck = 0;
		}

		if (leapCheck == 1) {
			printf("%d is a leap year\n", year);
		} else if (leapCheck == 0) {
			printf("%d is not a leap year\n", year);
		}

		printf("Repeat Program?: ");
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