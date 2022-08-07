/* Write a C program to check whether a number is even or odd */

#include <stdio.h>
#include <conio.h>

int main() {
	int num;

	printf("Enter the number to check: ");
	scanf("%d", & num);

	if (num % 2 == 0) {
		printf("%d is even\n", num);
	} else if (num % 2 != 0) {
		printf("%d is odd\n", num);
	}

	getch();
	return 0;
}