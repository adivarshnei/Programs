//Write a program to calculate simple interest

#include<stdio.h>
#include<conio.h>

int main(void) {
	float princ, rate, time, interest;

	printf("Enter the principal amount: ");
	scanf("%f", & princ);
	printf("Enter the rate: ");
	scanf("%f", & rate);
	printf("Enter the time: ");
	scanf("%f", & time);

	interest = (princ * rate * time) / 100;

	printf("The simple interest is: %.2f", interest);

	getch();
	return 0;
}