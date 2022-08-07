//Write a C program to convert a given integer (in days) to years, weeks and days

#include<stdio.h>
#include<conio.h>

int main(void) {
	clrscr(); 
	
	int raw, y, w, d;

	printf("Enter the total days: ");
	scanf("%d", & raw);

	y = raw / 365;
	w = (raw - (365 * y)) / 7;
	d = (raw - (365 * y) - (w * 7));

	printf("%d seconds is %d:%d:%d", raw, y, w, d);

	getch();
	return 0;
}