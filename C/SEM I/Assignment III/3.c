/* 

Assignemnt III
Name: Adersh Varshnei
3. Write a C Program to find HCF (GCD) of two numbers

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

void hcfDef(int, int, int * );

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputFirstNum, inputSecondNum;
		int HCF;

		printf("Enter the two numbers of which the HCF is to be found (Negative numbers will be considered as positive): ");
		scanf("%d%d", & inputFirstNum, & inputSecondNum);

		hcfDef(abs(inputFirstNum), abs(inputSecondNum), & HCF);

		printf("Highest Common Factor of %d and %d is: %d", abs(inputFirstNum), abs(inputSecondNum), HCF);

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

void hcfDef(int firstNum, int secondNum, int * HCF) {
	loopVar i;
	int smallerNum;

	smallerNum = (firstNum < secondNum) ? firstNum : secondNum;

	for (i = 1; i <= smallerNum; i++) {
		if (firstNum % i == 0 && secondNum % i == 0) {
			* HCF = i;
		} //if (firstNum % i == 0 && secondNum % i == 0) 
	} //for (i = 1; i <= smallerNum; i++)
} //void hcfDef(int firstNum, int secondNum, int * HCF)