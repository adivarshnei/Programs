/* 

Assignemnt II
Name: Adersh Varshnei
1. Write a C Program to print all alphabets from a to z 

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

void printAlpha(void);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		printf("List of Alphabets: \n");
		
		printAlpha();

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

void printAlpha(void) {
	char alpha = 'a';
	loopVar i;

	for (i = 1; i <= 26; i++, alpha++) {
		printf("Letter %d = %c%c\n", i, toupper(alpha), alpha);
	} //for (i = 1; i <= 26; i++, alpha++) 
} //void printAlpha(void) 