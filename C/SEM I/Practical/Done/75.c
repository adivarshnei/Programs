/* Write a program to compare two strings */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//************************************************************************

enum boolFlag {
	TRUE = 1,
	FALSE
}; //enum boolFlag

//************************************************************************he

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

//************************************************************************

enum boolFlag strngCmp(string * , string * );

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		string str1[50], str2[50];
		enum boolFlag flag;

		printf("Enter the first string: ");
		gets(str1);

		printf("Enter the second string: ");
		gets(str2);

		flag = strngCmp(str1, str2);

		switch (strngCmp(str1, str2)) {
			case TRUE:
				printf("The strings are identical.\n");

				break;

			case FALSE:
				printf("The strings are not identical.\n");

				break;
		} //switch (strngCmp(str1, str2))

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

enum boolFlag strngCmp(string * str1, string * str2) {
	loopVar i;
	enum boolFlag flag = TRUE;

	if (strlen(str1) == strlen(str2)) {
		for (i = 0; * (str1 + i) != '\0' && * (str2 + i) != '\0'; i++) {
			if ( * (str1 + i) != * (str2 + i)) {
				flag = FALSE;
			} //if ( * (str1 + i) != * (str2 + i))
		} //for (i = 0; * (str1 + i) != '\0' && * (str2 + i) != '\0'; i++)
	} else {
		flag = FALSE;
	} //End of extended if clause

	return flag;
} //enum boolFlag strngCmp(string * str1, string * str2)