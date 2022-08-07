/* Write a C program to swap two variables by using a third variable */

#include<stdio.h>
#include<conio.h>

int main(void) {
	clrscr(); 
	
	float a1, a2, a3;

	printf("Enter the two variables: ");
	scanf("%f%f", & a1, & a2);

	printf("Unswapped Numbers: %.2f, %.2f \n", a1, a2);

	a3 = a1;
	a1 = a2;
	a2 = a3;

	printf("Swapped Numbers: %.2f, %.2f ", a1, a2);

	getch();
	return 0;
}