/* 

Assignemnt II
Name: Adersh Varshnei
5. Write a C Program to count number of digits in a number

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

long int digCounter(long int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		long int inputNum;

		printf("Enter the number: ");
		scanf("%ld", & inputNum);

		printf("The number of digits in %ld is %ld", inputNum, digCounter(inputNum));

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

long int digCounter(long int num) {
	static int digCount;
	static int repChk;

	if (count > repChk) {
		digCount = 0;
		repChk = count;
	} //if (count > repChk)

	if (num > 0) {
		digCount++;
		return digCounter(num / 10);
	} else {
		return digCount;
	} //End of extended if clause
} //long int digCounter(long int num)