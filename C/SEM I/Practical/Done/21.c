/* Write a program in C to accept an integer numbers and find reverse of this number and check this number for palindrome */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num, revNum = 0, i;

		printf("Enter the Number (Negative Numbers Will be Converted to Positive): ");
		scanf("%d", & num);

		num = abs(num);

		printf("\nGiven Number: %d\n", num);
		printf("Reverse of Number: ");

		for (i = num; i > 0; i /= 10) {
			revNum *= 10;
			revNum += i % 10;

			if(revNum==0){
				printf("0");
			}
		}

		printf("%d\n", revNum);

		if (revNum == num) {
			printf("%d is a palindrome\n", num);
		} else {
			printf("%d is not a palindrome\n", num);
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