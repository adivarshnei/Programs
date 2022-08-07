/* Write a C program that accepts two item's weight (floating points' values) and number of purchase (floating points' values) and calculate the average value of the items */

#include<stdio.h>
#include<conio.h>

int main(void) {
	clrscr(); 
	
	float w1, w2;
	int n1, n2;
	float ave;

	printf("Enter the weights of the two items: ");
	scanf("%f%f", & w1, & w2);

	printf("Enter the number of the two items purchased: ");
	scanf("%d%d", & n1, & n2);

	ave = ((w1 * n1) + (w2 * n2)) / (n1 + n2);

	printf("The average weight is %.2f", ave);

	getch();
	return 0;
}