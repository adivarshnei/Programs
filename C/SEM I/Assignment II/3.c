/* 

Assignemnt II
Name: Adersh Varshnei
3. Write a C Program to find sum of all odd numbers between 1 to n

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

long int sumCalc(int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int noOfTerms;
		long int sum;

		printf("Enter the upper limit of terms: ");
		scanf("%d", & noOfTerms);

		printf("Sum of all odd numbers upto %d are given by: \n", noOfTerms);

		sum = sumCalc(noOfTerms);

		printf("\n= %ld", sum);

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

long int sumCalc(int n) {
	long int sum = 0;
	loopVar i;

	for (i = 1; i <= n; i += 2) {
		sum += i;

		if (i + 2 > n) {
			printf("%d", i);
		} else {
			printf("%d + ", i);
		} //End of extended if clause
	} //for (i = 1; i <= n; i += 2)

	return sum;
} //long int sumCalc(int n)