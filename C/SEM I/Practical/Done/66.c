/* Write a program in ‘C’ that compares two given dates. To store a date, use a struct that contains three members namely day, month, and year. If the dates are equal, then display message as “equal” otherwise “Unequal” */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************

enum boolFlag {
	TRUE = 1,
	FALSE
}; //enum boolFlag

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************

struct date {
	int day;
	int month;
	int year;
}; //struct date

//************************************************************************

void dataEntry(struct date * );
enum boolFlag dateEval(struct date, struct date);

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		struct date inputFirstDate, inputSecondDate;

		printf("Enter the first date: \n");
		dataEntry( & inputFirstDate);

		printf("Enter the second date: \n");
		dataEntry( & inputSecondDate);

		printf("Date 1: %d/%d/%d\n", inputFirstDate.day, inputFirstDate.month, inputFirstDate.year);
		printf("Date 1: %d/%d/%d\n", inputSecondDate.day, inputSecondDate.month, inputSecondDate.year);

		if (dateEval(inputFirstDate, inputSecondDate) == TRUE) {
			printf("\nEqual");
		} else {
			printf("\nUnequal");
		} //End of extended if clause

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);
		scanf("%c", & temp);

		count++;

		if (count >= 15) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		} //if (count >= 15) 
	} //while (rep == 1) 

	printf("Normal END\n");

	getch();
	return 0;
} //int main(void)

//************************************************************************

void dataEntry(struct date * data) {
	enum boolFlag flag;
	enum boolFlag leapFlag;

	do {
		flag = TRUE;

		printf("Year: ");
		scanf("%d", & data -> year);

		if (data -> year < 0) {
			printf("Invalid year entry. Please enter again.\n");
			flag = FALSE;
		} //if (data -> year < 0)
	} while (flag == FALSE);

	do {
		flag = TRUE;

		printf("Month: ");
		scanf("%d", & data -> month);

		if (data -> month < 1 || data -> month > 12) {
			printf("Invalid month entry. Please enter again.\n");
			flag = FALSE;
		} //if (data -> month < 1 || data -> month > 12)
	} while (flag == FALSE);

	do {
		flag = TRUE;

		printf("Date: ");
		scanf("%d", & data -> day);

		switch (data -> month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (data -> day < 1 || data -> day > 31) {
					printf("Invalid day entry. Please enter again.\n");
					flag = FALSE;
				} //if (data -> day < 1 || data -> day > 31)

				break;

			case 4:
			case 6:
			case 9:
			case 11:
				if (data -> day < 1 || data -> day > 30) {
					printf("Invalid day entry. Please enter again.\n");
					flag = FALSE;
				} //if (data -> day < 1 || data -> day > 30)

				break;

			case 2:
				if (data -> year % 4 == 0 && data -> year % 400 == 0) {
					leapFlag = TRUE;
				} else if (data -> year % 4 == 0 && data -> year % 100 == 0) {
					leapFlag = FALSE;
				} else if (data -> year % 4 == 0) {
					leapFlag = TRUE;
				} else {
					leapFlag = FALSE;
				} //End of extended if clause

				if (leapFlag == TRUE) {
					if (data -> day < 1 || data -> day > 29) {
						printf("Invalid day entry. Please enter again.\n");
						flag = FALSE;
					} //if (data -> day < 1 || data -> day > 29)
				} else if (leapFlag == FALSE) {
					if (data -> day < 1 || data -> day > 28) {
						printf("Invalid day entry. Please enter again.\n");
						flag = FALSE;
					} //if (data -> day < 1 || data -> day > 28)
				} //End of extended if clause

				break;
		} //switch (data -> month)
	} while (flag == FALSE);
} //void dataEntry(struct date * data)

//************************************************************************

enum boolFlag dateEval(struct date firstDate, struct date secondDate) {
	if (
		firstDate.day == secondDate.day &&
		firstDate.month == secondDate.month &&
		firstDate.year == secondDate.year) {
		return TRUE;
	} else {
		return FALSE;
	} //End of extended if clause
} //enum boolFlag dateEval(struct date firstDate, struct date secondDate)