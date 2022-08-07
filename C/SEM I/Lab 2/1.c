// Write a program find area of a circle

#include <stdio.h>
#include <conio.h>

#define PI 3.14

int main(void) {
	clrscr();

	float r;
	float area;

	printf("Enter the radius: ");
	scanf("%f", & r);

	area = PI * r * r;

	printf("The area of circle is %.2f", area);

	getch();
	return 0;
}