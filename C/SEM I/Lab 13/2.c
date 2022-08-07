#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef unsigned int loopVar;
typedef char bufferClear;

struct dateParameters {
	int day;
	int month;
	int year;
};

void dataEntry(struct dateParameters * );

int count = 0;
bufferClear temp;

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		struct dateParameters date[2];

		printf("Enter first date: \n");
		dataEntry( & date[0]);
		printf("Enter second date: \n");
		dataEntry( & date[1]);

		printf("Date 1: %d/%d/%d\n", date[0].day, date[0].month, date[0].year);
		printf("Date 2: %d/%d/%d\n", date[1].day, date[1].month, date[1].year);

		if (date[0].day == date[1].day &&
			date[0].month == date[1].month &&
			date[0].year == date[1].year) {
			printf("The dates are identical\n");
		} else {
			printf("The dates are different\n");
		}

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);
		scanf("%c", & temp);

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

void dataEntry(struct dateParameters * date) {
	printf("Enter day: ");
	scanf("%d", & date -> day);
	printf("Enter month: ");
	scanf("%d", & date -> month);
	printf("Enter year: ");
	scanf("%d", & date -> year);
}