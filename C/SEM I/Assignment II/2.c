/* 

Assignemnt II
Name: Adersh Varshnei
2. Write a C Program to print all even numbers between 1 and 100 

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

void printNos(void);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		printf("List of even numbers between 1 and 100: \n");
		printNos();

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

void printNos(void) {
	loopVar i;

	for (i = 2; i <= 100; i += 2) {
		printf("Even number %d: %d\n", (i / 2), i);
	} //for (i = 2; i <= 100; i += 2)
} //void printNos(void)