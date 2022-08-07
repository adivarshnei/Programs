#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

//************************************************************************

typedef unsigned int loopVar;
typedef char string;

//************************************************************************

void freqTable(string[50]);

//************************************************************************

int count = 0;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		loopVar i;
		string text[50];

		printf("Enter the string: ");
		scanf("%s", text);

		freqTable(text);

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

//************************************************************************

void freqTable(string text[50]) {
	char freqTable[26][2];
	char i, j, k;

	for (i = 'a', j = 0; i <= 'z'; i++, j++) {
		freqTable[j][0] = i;
		freqTable[j][1] = 0;
	} //for (i = 'a', j = 0; i <= 'z'; i++, j++)

	for (i = 0; text[i] != '\0'; i++) {
		for (j = 'a', k = 0; j <= 'z'; j++, k++) {
			if (j == tolower(text[i])) {
				freqTable[k][1]++;
			} //if (j == tolower(text[i]))
		} //for (j = 'a', k = 0; j <= 'z'; j++, k++)
	} //for (i = 0; text[i] != '\0'; i++)

	printf("|---------+-----------|\n");
	printf("|  Digit  | Frequency |\n");
	printf("|---------+-----------|\n");

	for (i = 0; i < 26; i++) {
		printf("|%5c    |%6d     |\n", freqTable[i][0], freqTable[i][1]);
	} //for (i = 0; i < 26; i++)

	printf("|---------+-----------|\n");
} //void freqTable(string text[50])