/* Write a program to copy the contents of one file to another file */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

//************************************************************************

int count = 0;
bufferClear temp;
string tempStr[100];

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		FILE * file1, * file2;
		string * inputStr, * buffer;
		char readChar;

		printf("Enter a string for the first file: ");
		gets(tempStr);

		inputStr = (string * ) malloc(strlen(tempStr) + 1);
		buffer = (string * ) malloc(strlen(tempStr) + 1);

		if (inputStr == NULL || buffer == NULL) {
			printf("Data allocation unsuccessful.\n");

			getch();
			exit(0);
		} //if (inputStr == NULL || buffer == NULL)

		strcpy(inputStr, tempStr);

		file1 = fopen("72file1.txt", "w");

		if (file1 == NULL) {
			printf("File opening unsuccessful. Exiting program");

			getch();
			exit(0);
		} //if (file1 == NULL || file2 == NULL)

		fprintf(file1, inputStr);

		fclose(file1);

		file1 = fopen("72file1.txt", "r");
		file2 = fopen("72file2.txt", "w");

		if (file1 == NULL || file2 == NULL) {
			printf("File opening unsuccessful. Exiting program");

			getch();
			exit(0);
		} //if (file1 == NULL || file2 == NULL)

		fgets(buffer, strlen(inputStr) + 1, file1);
		fprintf(file2, buffer);

		fclose(file1);
		fclose(file2);

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