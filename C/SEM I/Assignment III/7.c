/* 

Assignemnt III
Name: Adersh Varshnei
7. Write a C Program to print all Stong numbers between 1 and n

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef unsigned long int longLoopVar;
typedef unsigned long int intArr;

//************************************************************************************************

long int factorial(int);
int strongChk(long int);
intArr * retrnStrongNumList(long int, int * );

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		loopVar i;
		long int inputLim;
		intArr * strongList;
		int cardinality = 0;

		printf("Enter the limit upto which Strong numbers are to be found: ");
		scanf("%ld", & inputLim);

		strongList = retrnStrongNumList(inputLim, & cardinality);

		printf("The Strong Numbers lower than %ld are: \n", inputLim);

		for (i = 0; i < cardinality; i++) {
			printf("%ld \t", strongList[i]);
		} //for (i = 0; i < cardinality; i++)

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

long int factorial(int num) {
	if (num >= 1) {
		return num * factorial(num - 1);
	} else {
		return 1;
	} //End of extended if clause
} //long int factorial(int num)

//************************************************************************************************

int strongChk(long int num) {
	long int factSum = 0, temp = num;

	for (; temp > 0; temp /= 10) {
		factSum += factorial(temp % 10);
	} //for (; temp > 0; temp /= 10)

	if (factSum == num) {
		return 1;
	} else {
		return 0;
	} //End of extended if clause
} //int strongChk(long int num)

//************************************************************************************************

intArr * retrnStrongNumList(long int num, int * cardinality) {
	static intArr strongList[10];
	static int repChk;
	longLoopVar i;
	int indexVar = 0;

	if (count > repChk) {
		for (i = 0; i < 10; i++) {
			strongList[i] = 0;
		} //for (i = 0; i < 10; i++)

		repChk = 1;
	} //if (count > repChk)

	for (i = 1; i < num; i++) {
		if (strongChk(i) == 1) {
			strongList[indexVar] = i;

			indexVar++;
			++( * cardinality);
		} //if (strongChk(i) == 1)
	} //for (i = 1; i < num; i++) 

	return strongList;
} //intArr * retrnStrongNumList(long int num, int * cardinality)