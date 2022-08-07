/* 

Assignemnt IV
Name: Adersh Varshnei
9. Write a C Program to find GCD (HCF) of two numbers using recursion

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

int hcfGen(int, int);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputFirstNum, inputSecondNum;
		int HCF;

		printf("Enter the first number (Negative Numbers will be considered as positive): ");
		scanf("%d", & inputFirstNum);

		printf("Enter the second number (Negative Numbers will be considered as positive): ");
		scanf("%d", & inputSecondNum);

		HCF = hcfGen(abs(inputFirstNum), abs(inputSecondNum));

		printf("HCF of %d and %d is %d", abs(inputFirstNum), abs(inputSecondNum), HCF);

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

//************************************************************************************************

int hcfGen(int firstNum, int secondNum) {
	if (secondNum != 0) {
		return hcfGen(secondNum, firstNum % secondNum);
	} else {
		return firstNum;
	} //End of extended if clause
} //int hcfGen(int num1, int num2)