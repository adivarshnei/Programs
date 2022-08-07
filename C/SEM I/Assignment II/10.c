/* 

Assignemnt II
Name: Adersh Varshnei
10. Write a C Program to print all ASCII character with their values

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

void printASCII(void);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		printf("The following is the ASCII Table: \n");

		printASCII();

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

void printASCII(void) {
	loopVar i;

	for (i = 0; i <= 255; i++) {
		if (i == 0) {
			printf("\nASCII Control Characters: \n");
		} else if (i == 32) {
			printf("-------------+-------------\n");
			printf("\nASCII Printable Characters: \n");
		} else if (i == 128) {
			printf("-------------+-------------\n");
			printf("\nExtended ASCII Code: \n");
		} //End of extended if clause

		if (i == 0 || i == 32 || i == 128) {
			printf("-------------+-------------\n");
			printf(" ASCII Value |  Character  \n");
		} //End of extended if clause

		if (i < 100) {
			printf("-------------+-------------\n");
			printf("%7d      |%7c      \n", i, (char) i);
		} else {
			printf("-------------+-------------\n");
			printf("%8d     |%7c      \n", i, (char) i);
		} //End of extended if clause
	} //for (i = 0; i <= 255; i++)

	printf("-------------+-------------\n");
} //void printASCII(void)