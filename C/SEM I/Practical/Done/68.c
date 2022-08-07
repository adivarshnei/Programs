/* Write a program which will read a text and count all occurrences of all characters which are part of text */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;
typedef char charMatrix;

//************************************************************************

void printFreqTable(string * );

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		string inputStr[100];

		printf("Enter the string: ");
		gets(inputStr);

		printFreqTable(inputStr);

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

void printFreqTable(string * str) {
	loopVar i;
	charMatrix freqTable[255][2];

	for (i = 0; i < 255; i++) {
		freqTable[i][0] = i;
		freqTable[i][1] = 0;
	} //for (i = 0; i < 255; i++)

	for (i = 0;*(str + i) != '\0'; i++) {
		freqTable[(int)( * (str + i))][1]++;
	} //for (i = 0; * (str + i) != '\0'; i++)

	printf("|-----------+-----------|\n");
	printf("| Character | Frequency |\n");
	printf("|-----------+-----------|\n");

	for (i = 0; i < 255; i++) {
		if (freqTable[i][1] != 0) {
			if (freqTable[i][0] == ' ') {
				printf("|   Space   |%6d     |\n", freqTable[i][1]);
			} else if (freqTable[i][0] == '\t') {
				printf("|    \\t     |%6d     |\n", freqTable[i][1]);
			} else {
				printf("|%6c     |%6d     |\n", (char) freqTable[i][0], freqTable[i][1]);
			} //End of extended if clause
		} //if (freqTable[i][1] != 0)
	} //for (i = 0; i < 255; i++)

	printf("|-----------+-----------|\n");
} //void printFreqTable(string * str)