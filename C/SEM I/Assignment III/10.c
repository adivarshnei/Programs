/* 

Assignemnt III
Name: Adersh Varshnei
10. Write a C Program to input martks of five subjects Physics, Chemistry, Biology, Mathematics and Computer. Calculate percentage and grade according to following:
Percentage >= 90% : Grade A 
Percentage >= 80% : Grade B 
Percentage >= 70% : Grade C 
Percentage >= 60% : Grade D 
Percentage >= 40% : Grade E 
Percentage < 40% : Grade F

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef float floatMatr;
typedef char string;

//************************************************************************************************

void gradeCalc(floatMatr[6][2], int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		loopVar i;
		floatMatr gradeTable[6][2];
		int maxMarks;
		static string * subjKey[6] = {
			"Physics",
			"Chemistry",
			"Biology",
			"Mathematics",
			"Computer",
			"Average"
		}; //static string * subjKey[6]

		printf("Enter maximum marks: ");
		scanf("%d", & maxMarks);

		for (i = 0; i < 5; i++) {
			do {
				printf("Enter the Marks for %s: ", subjKey[i]);
				scanf("%f", & gradeTable[i][0]);

				if (gradeTable[i][0] > maxMarks || gradeTable[i][0] < 0) {
					printf("Invalid Marks Entry. Enter Again\n");
				} //if (gradeTable[i][0] > maxMarks || gradeTable[i][0] < 0)
			} while (gradeTable[i][0] > maxMarks || gradeTable[i][0] < 0);
		} //for (i = 0; i < 5; i++)

		gradeCalc(gradeTable, maxMarks);

		printf("Marks Statement: \n");
		printf("|-------------+-----------+------------+-----------|\n");
		printf("|   Subject   |   Marks   | Percentage |   Grade   |\n");
		printf("|-------------+-----------+------------+-----------|\n");

		for (i = 0; i < 6; i++) {
			if (i == 0 || i == 2 || i == 5) {
				printf("|   %s   |%8.2f   |%8.2f%%   |%6c     |\n", subjKey[i], gradeTable[i][0], ((float) gradeTable[i][0] * 100.0) / (float) maxMarks, (int) gradeTable[i][1]);
			} else if (i == 1) {
				printf("|  %s  |%8.2f   |%8.2f%%   |%6c     |\n", subjKey[i], gradeTable[i][0], ((float) gradeTable[i][0] * 100.0) / (float) maxMarks, (int) gradeTable[i][1]);
			} else if (i == 3) {
				printf("| %s |%8.2f   |%8.2f%%   |%6c     |\n", subjKey[i], gradeTable[i][0], ((float) gradeTable[i][0] * 100.0) / (float) maxMarks, (int) gradeTable[i][1]);
			} else if (i == 4) {
				printf("|   %s  |%8.2f   |%8.2f%%   |%6c     |\n", subjKey[i], gradeTable[i][0], ((float) gradeTable[i][0] * 100.0) / (float) maxMarks, (int) gradeTable[i][1]);
			} //End of extended if clause

			printf("|-------------+-----------+------------+-----------|\n");
		} //for(i=0; i<6; i++)

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

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

//************************************************************************************************

void gradeCalc(floatMatr gradeTable[6][2], int maxMarks) {
	loopVar i;

	gradeTable[5][0] = (gradeTable[0][0] + gradeTable[1][0] + gradeTable[2][0] + gradeTable[3][0] + gradeTable[4][0]) / 5;

	for (i = 0; i < 6; i++) {
		if (gradeTable[i][0] >= (90.0 * maxMarks) / 100.0) {
			gradeTable[i][1] = 'A';
		} else if (gradeTable[i][0] >= (80.0 * maxMarks) / 100.0) {
			gradeTable[i][1] = 'B';
		} else if (gradeTable[i][0] >= (70.0 * maxMarks) / 100.0) {
			gradeTable[i][1] = 'C';
		} else if (gradeTable[i][0] >= (60.0 * maxMarks) / 100.0) {
			gradeTable[i][1] = 'D';
		} else if (gradeTable[i][0] >= (40.0 * maxMarks) / 100.0) {
			gradeTable[i][1] = 'E';
		} else {
			gradeTable[i][1] = 'F';
		} //End of extended if clause
	} //for (i = 0; i < 6; i++)
} //void gradeCalc(floatMatr gradeTable[6][2], int maxMarks) 