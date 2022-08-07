/* Write a program to calculate the sum of series: 2^4 + 6^4 + 10^4 + 14^4 + ... upto n terms */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;
	
	while (rep == 1) {
		float num = 2, sum = 0;
		unsigned int terms;
		unsigned int i;

		printf("Enter the number of terms: ");
		scanf("%d", &terms);

		for(i = 0; i < terms; i++, num+=4){
			printf("%.0f^4 + ", num);
			
			sum += pow(num,4);
		}


		printf("\b\b = %.0f", sum);
		
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