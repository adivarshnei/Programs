//Write a C program to convert a given integer (in seconds) to hours, minutes and seconds

#include<stdio.h>
#include<conio.h>

int main(void) {
	clrscr();

	unsigned int raw, h, m, s;
	
	printf("Enter the total seconds: ");
	scanf("%d", & raw);

	h = raw / 3600;
	m = (raw - (3600 * h)) / 60;
	s = (raw - (3600 * h) - (m * 60));

	printf("%d seconds is %d:%d:%d", raw, h, m, s);

	getch();
	return 0;
}