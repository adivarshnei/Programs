/* 

Assignemnt III
Name: Adersh Varshnei
8. Write a C Program to convert Hexadecimal to Decimal number system

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef char string;

//************************************************************************************************

int hexToDec(string[20], unsigned int * , string[20]);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		string inputHex[20], corrHex[20];
		int stringLen;
		loopVar i;

		for (i = 0; i < 20; i++) {
			inputHex[i] = 0;
			corrHex[i] = 0;
		} //for (i = 0; i < 20; i++) 

		printf("Enter the hexadecimal number: ");
		scanf("%s", inputHex);

		stringLen = strlen(inputHex);

		printf("%s in hexadecimal is %d in decimal.\n", corrHex, hexToDec(inputHex, & stringLen, corrHex));

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

int hexToDec(string hex[20], unsigned int * hexLen, string corrHex[20]) {
	int decimal = 0;
	loopVar i;
	int corrIndex = 0;
	int powIndex = 0;

	for (i = 0; i < * hexLen; i++) {
		if ((hex[i] >= '0' && hex[i] <= '9') || (toupper(hex[i]) >= 'A' && toupper(hex[i]) <= 'F')) {
			corrHex[corrIndex] = toupper(hex[i]);
			corrIndex++;
		} else {
			printf("%c is not a hexadecimal character. Ignoring said character.\n", hex[i]);
		} //End of extended if clause
	} //for (i = 0; i < * hexLen; i++)

	for (i = 0; i < corrIndex; i++) {
		switch (corrHex[i]) {
			case '0':
				decimal += 0 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case '1':
				decimal += 1 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case '2':
				decimal += 2 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case '3':
				decimal += 3 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case '4':
				decimal += 4 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case '5':
				decimal += 5 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case '6':
				decimal += 6 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case '7':
				decimal += 7 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case '8':
				decimal += 8 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case '9':
				decimal += 9 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case 'A':
				decimal += 10 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case 'B':
				decimal += 11 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case 'C':
				decimal += 12 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case 'D':
				decimal += 13 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case 'E':
				decimal += 14 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;

			case 'F':
				decimal += 15 * ((int) round(pow(16, strlen(corrHex) - powIndex - 1)));

				powIndex++;
				break;
		} //switch (corrHex[i])
	} //for (i = 0; i < corrIndex; i++) 

	return decimal;
} //int hexToDec(string hex[20], unsigned int * hexLen, string corrHex[20])