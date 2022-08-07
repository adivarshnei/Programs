/* Write a proram which will store ten integers to one file and stores the odd and even numbers to respective files */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;
typedef int intArr;

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		FILE * file1, * file2, * file3;
		intArr inputInt[10];
		int readInt;
		loopVar i;

		printf("Enter the ten integers: ");

		for (i = 0; i < 10; i++) {
			scanf("%d", & inputInt[i]);
		} //for (i = 0; i < 10; i++)

		file1 = fopen("74file1.txt", "w");

		if (file1 == NULL) {
			printf("File opening unsuccessful. Exiting program");

			getch();
			exit(0);
		} //if (file1 == NULL)

		for (i = 0; i < 10; i++) {
			fprintf(file1, "%d\t", inputInt[i]);
		} //for (i = 0; i < 10; i++)

		fclose(file1);

		file1 = fopen("74file1.txt", "r");
		file2 = fopen("74file2.txt", "w");
		file3 = fopen("74file3.txt", "w");

		if (file1 == NULL || file2 == NULL || file3 == NULL) {
			printf("File opening unsuccessful. Exiting program");

			getch();
			exit(0);
		} //if (file1 == NULL || file2 == NULL || file3 == NULL)

		for (i = 0; i < 10; i++) {
			fscanf(file1, "%d", & readInt);

			if (readInt % 2 == 0) {
				fprintf(file2, "%d\t", readInt);
			} else {
				fprintf(file3, "%d\t", readInt);
			} //End of extended if clause
		} //for (i = 0; i < 10; i++)

		fclose(file1);
		fclose(file2);
		fclose(file3);

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