/* Write a program which reads your name from the keyboard and outputs a list of ASCII codes, which represent your name */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

//************************************************************************

void ASCIIPrint(string * );

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		string inputStr[50];

		printf("Enter the name: ");
		gets(inputStr);

		ASCIIPrint(inputStr);

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

void ASCIIPrint(string * name) {
	loopVar i;

	printf("|-----------+------------|\n");
	printf("| Character | ASCII Code |\n");
	printf("|-----------+------------|\n");

	for (i = 0; *(name + i) != '\0'; i++) {
		printf("|%6c     |%7d     |\n", *(name + i), *(name + i));
		printf("|-----------+------------|\n");
	} //for (i = 0; *(name + i) != '\0'; i++)
} //void ASCIIPrint(string * name)