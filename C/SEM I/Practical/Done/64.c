/* Declare a structure name student containing members name, roll_no, marks. Create an array of 30 such students. Write a program to read and display the contents of array */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//************************************************************************

enum choice {
	READ = 1,
	WRITE,
	EXIT
}; //enum choice

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

//************************************************************************

struct student {
	string * name;
	unsigned int roll_no;
	unsigned int marks;
}; //struct student

//************************************************************************

struct indices {
	int data;
	int read;
}; //struct indices

//************************************************************************

void dataEntry(struct student * );
void dataDisplay(struct student);

//************************************************************************

int count = 0;
bufferClear temp;
string tempStr[50];

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		loopVar i;
		struct student stData[30];
		enum choice menuOption;
		struct indices index;

		index.data = 0;

		do {
			printf("1. Read Student Data\n");
			printf("2. Write Student Data\n");
			printf("3. Exit\n");
			printf("Enter Option: ");
			scanf("%d", & menuOption);

			switch (menuOption) {
				case READ:
					if (index.data == 0) {
						printf("No data to read\n");
					} else {
						do {
							printf("Enter data index to read: ");
							scanf("%d", & index.read);
							if (index.read >= 0 && index.read < index.data) {
								dataDisplay(stData[index.read]);

								break;
							} else {
								printf("Invalid Entry. Please Enter again\n");
							} //End of extended if clause
						} while (index.read < 0 || index.read > index.data);
					} //End of extended if clause

					break;

				case WRITE:
					if (index.data >= 30) {
						printf("Overflow Error\n");
					} else {
						dataEntry( & stData[index.data]);
						index.data++;
					} //End of extended if clause

					break;

				case EXIT:
					break;

				default:
					printf("Invalid Entry. Please enter again.\n");
					getch();

					break;
			} //switch (menuOption)
		} while (menuOption != EXIT);

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

//************************************************************************

void dataEntry(struct student * stData) {
	printf("Enter the name: ");
	scanf("%c", & temp);
	gets(tempStr);

	stData -> name = (string * ) malloc(strlen(tempStr) + 1);

	if (stData -> name == NULL) {
		printf("Data allocation unsuccessful.\n");

		getch();
		exit(0);
	} //if (stData -> name == NULL)

	strcpy(stData -> name, tempStr);

	printf("Enter the roll number: ");
	scanf("%d", & stData -> roll_no);

	printf("Enter the marks: ");
	scanf("%d", & stData -> marks);

	stData -> roll_no = abs(stData -> roll_no);
	stData -> marks = abs(stData -> marks);
} //void dataEntry(struct student * stData)

//************************************************************************

void dataDisplay(struct student stData) {
	printf("Name: %s\n", stData.name);
	printf("Roll No: %d\n", stData.roll_no);
	printf("Marks: %d\n", stData.marks);
} //void dataDisplay(struct student stData)