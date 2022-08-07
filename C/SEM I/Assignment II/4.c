/* 

Assignemnt II
Name: Adersh Varshnei
4. Write a C Program to print multiplication table of any number

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

int count = 0;

//************************************************************************************************

void mulTable(long int[][3]);
void printTable(long int[][3]);

//************************************************************************************************

int main(void) {
	int rep = 1;

	while (rep == 1) {
		long int table[10][3];

		printf("Enter the number whose table is to be printed: ");
		scanf("%ld", & table[0][0]);

		printf("Multiplication Table of %ld is: \n", table[0][0]);

		mulTable(table);

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

void mulTable(long int table[10][3]) {
	loopVar i;

	for (i = 0; i < 10; i++) {
		table[i][0] = table[0][0];
		table[i][1] = i + 1;
		table[i][2] = table[i][0] * table[i][1];
	} //for (i = 0; i < 10; i++) 

	printTable(table);
} //void mulTable(long int table[10][3]) 

//************************************************************************************************

void printTable(long int table[10][3]) {
	loopVar i;

	for (i = 0; i < 10; i++) {
		printf("%ld\t*\t%ld\t=\t%ld\n", table[i][0], table[i][1], table[i][2]);
	} //for (i = 0; i < 10; i++)
} //void printTable(long int table[10][3])