/* Write a program which reads a string from the keyboard and determines whether the string is a palindrome (Ignore Capitalization) */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//************************************************************************

enum boolFlag {
	TRUE = 1,
	FALSE
}; //enum boolFlag

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

//************************************************************************

void revStrGen(string * , string * );
enum boolFlag palinChk(string * );

//************************************************************************

string tempStr[100];
int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		enum boolFlag palinFlag;

		printf("Enter the string: ");
		gets(tempStr);

		palinFlag = palinChk(tempStr);

		switch (palinFlag) {
			case TRUE:
				printf("The string %s is a palindrome.\n", tempStr);

				break;

			case FALSE:
				printf("The string %s is not a palindrome\n", tempStr);

				break;
		} //switch (palinFlag)

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

void revStrGen(string * str, string * revStr) {
	loopVar i;

	for (i = 0; i < strlen(str); i++) {
		* (revStr + i) = * (str + (strlen(str) - (i + 1)));
	} //for (i = 0; i < strlen(str); i++)

	* (revStr + i) = '\0';
} //void revStrGen(string * str, string * revStr)

//************************************************************************

enum boolFlag palinChk(string * tempStr) {
	string * str, * revStr;
	loopVar i;

	str = (string * ) malloc(strlen(tempStr) + 1);
	revStr = (string * ) malloc(strlen(tempStr) + 1);

	if (str == NULL || revStr == NULL) {
		printf("Data allocation unsuccessful.\n");

		getch();
		exit(0);
	} //if (str == NULL || revStr == NULL)

	strcpy(str, tempStr);

	for (i = 0; i < strlen(str); i++) {
		* (str + i) = tolower( * (str + i));
	} //for (i = 0; i < strlen(str); i++)

	revStrGen(str, revStr);

	printf("Original String: %s\n", str);
	printf("Reversed String: %s\n", revStr);

	if (!strcmp(str, revStr)) {
		return TRUE;
	} else {
		return FALSE;
	} //End of extended if clause
} //enum boolFlag palinChk(string * tempStr)