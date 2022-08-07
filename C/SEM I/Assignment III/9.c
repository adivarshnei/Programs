/* 

Assignemnt III
Name: Adersh Varshnei
9. Write a C Program to input week number and print weekday

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef char string;

//************************************************************************************************

string * wkDayPrint(int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		unsigned int wkNum;
		string * wkDay;

		do {
			printf("Enter the week number: ");
			scanf("%d", & wkNum);

			if (wkNum < 1 || wkNum > 7) {
				printf("Invalid week number entered. Enter again\n");
			} //if (wkNum < 1 || wkNum > 7)
		} while (wkNum < 1 || wkNum > 7);

		wkDay = wkDayPrint(wkNum);

		printf("Day %d of the week is %s", wkNum, wkDay);

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

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

//************************************************************************************************

string * wkDayPrint(int wkNum) {
	string * wkList[7] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	}; //string * wkList[7]

	return wkList[wkNum - 1];
} //string * wkDayPrint(int wkNum)