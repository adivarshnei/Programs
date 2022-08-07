/* Write a program in C to accept an integer number and to check whether it is Armstrong Number or not */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num, cubeSum = 0, i, a;

		printf("Enter the number: ");
		scanf("%d", & num);

		for (i = num; i > 0; i /= 10) {
			a = (i%10)*(i%10)*(i%10);
			cubeSum += a;
		}

		if(cubeSum==num){
			printf("\nThe number is an Armstrong Number\n");
		}else{
			printf("\nThe number is not an Armstrong Number\n");
		}

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

		count++;

		if (count >= 50) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		}

	}

	printf("Normal END\n");

	getch();
	return 0;
}