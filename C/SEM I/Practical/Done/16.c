/* Write a program in C to calculate and print the Electricity bill of a given customer. The customer idand unit consumed by the user should be taken from the keyboard and display the total amount to pay to the customer.
upto 199------------1.20
200-500-------------1.80
Above 500----------2.00
If bill exceeds Rs. 400 then a surcharge of 15% will be charged and the minimum bill should be of Rs. 100/- */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef char string;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		string firstName[30], lastName[30], id[10];
		unsigned int units;
		float charge, surcharge, total;

		printf("Enter the name of the customer: ");
		scanf("%s%s", firstName, lastName);
		printf("Enter the id of the customer: ");
		scanf("%s", id);
		printf("Enter the number of units consumed by the customer: ");
		scanf("%d", & units);

		if (units <= 199) {
			charge = 1.20;
		} else if (units >= 200 && units <= 500) {
			charge = 1.80;
		} else if (units > 500) {
			charge = 2.00;
		}

		printf("Customer name:              %s %s\n", firstName, lastName);
		printf("Customer id:                %s\n", id);
		printf("Units consumed:             %d\n", units);
		printf("Price per unit:             %.2f\n", charge);
		printf("Minimum charges:            100\n");

		total = units * charge;

		if (total >= 400) {
			printf("Charges before additionals: %.2f\n", total);
			total = (total * 115) / 100;
			printf("Surcharge applied:          15%%\n");
			printf("Total charges:              %.2f\n", total);
		} else if (total <= 100) {
			total = 100.00;
			printf("Total charges:              %.2f\n", total);
		} else {
			printf("Total charges:              %.2f\n", total);
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