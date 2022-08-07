/* 

Assignemnt IV
Name: Adersh Varshnei
10. Write a C Program to find LCM of two numbers using recursion using function

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

int lcmGen(int, int);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputFirstNum, inputSecondNum;
		int LCM;

		printf("Enter the first number (Negative Numbers will be considered as positive): ");
		scanf("%d", & inputFirstNum);

		printf("Enter the second number (Negative Numbers will be considered as positive): ");
		scanf("%d", & inputSecondNum);

		LCM = lcmGen(abs(inputFirstNum), abs(inputSecondNum));

		printf("Least Common Multiple of %d and %d is %d", abs(inputFirstNum), abs(inputSecondNum), LCM);

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

int lcmGen(int firstNum, int secondNum) {
	static loopVar i = 0;
	static int repChk;

	if (count > repChk) {
		repChk = count;
		i = 0;
	} //if (count > repChk)

	i += (firstNum < secondNum) ? firstNum : secondNum;

	if (i % firstNum == 0 && i % secondNum == 0) {
		return i;
	} else {
		return lcmGen(firstNum, secondNum);
	}//End of extended if clause
}//int lcmGen(int firstNum, int secondNum)