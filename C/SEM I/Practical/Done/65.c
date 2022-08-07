/* Write a simple database program in C which stores personal details of 100 persons such as Name, Date of Birth, Address, Phone Number etc. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//************************************************************************

enum choice {
	READ = 1,
	WRITE,
	EXIT
}; //enum choice

//************************************************************************

enum boolFlag {
	TRUE = 1,
	FALSE
}; //enum boolFlag

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

//************************************************************************

struct dateOfBirth {
	int day;
	int month;
	int year;
}; //struct dateOfBirth

//************************************************************************

struct database {
	string * name;
	struct dateOfBirth birthDate;
	string * address;
	string * phoneNum;
}; //struct database

//************************************************************************

struct indices {
	int data;
	int read;
}; //struct indices

//************************************************************************

void dataEntry(struct database * );
void dataDisplay(struct database);

//************************************************************************

int count = 0;
bufferClear temp;
string tempStr[50];

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		loopVar i;
		struct database data[100];
		enum choice menuOption;
		struct indices index;

		index.data = 0;

		do {
			printf("1. Read Data\n");
			printf("2. Write Data\n");
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
								dataDisplay(data[index.read]);

								break;
							} else {
								printf("Invalid Entry. Please Enter again\n");
							} //End of extended if clause
						} while (index.read < 0 || index.read > index.data);
					} //End of extended if clause

					break;

				case WRITE:
					if (index.data >= 100) {
						printf("Overflow Error\n");
					} else {
						dataEntry( & data[index.data]);
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

void dataEntry(struct database * data) {
	enum boolFlag flag;
	enum boolFlag leapFlag;
	loopVar i;

	printf("Enter the name: ");
	scanf("%c", & temp);
	gets(tempStr);

	data -> name = (string * ) malloc(strlen(tempStr) + 1);

	if (data -> name == NULL) {
		printf("Data allocation unsuccessful.\n");

		getch();
		exit(0);
	} //if (data -> name == NULL)

	strcpy(data -> name, tempStr);

	printf("Enter the date of birth (in numbers): \n");

	do {
		flag = TRUE;

		printf("Year: ");
		scanf("%d", & data -> birthDate.year);

		if (data -> birthDate.year < 0) {
			printf("Invalid year entry. Please enter again.\n");
			flag = FALSE;
		} //if (data -> birthDate.year < 0)
	} while (flag == FALSE);

	do {
		flag = TRUE;

		printf("Month: ");
		scanf("%d", & data -> birthDate.month);

		if (data -> birthDate.month < 1 || data -> birthDate.month > 12) {
			printf("Invalid month entry. Please enter again.\n");
			flag = FALSE;
		} //if (data -> birthDate.month < 1 || data -> birthDate.month > 12)
	} while (flag == FALSE);

	do {
		flag = TRUE;

		printf("Date: ");
		scanf("%d", & data -> birthDate.day);

		switch (data -> birthDate.month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (data -> birthDate.day < 1 || data -> birthDate.day > 31) {
					printf("Invalid day entry. Please enter again.\n");
					flag = FALSE;
				} //if (data -> birthDate.day < 1 || data -> birthDate.day > 31)

				break;

			case 4:
			case 6:
			case 9:
			case 11:
				if (data -> birthDate.day < 1 || data -> birthDate.day > 30) {
					printf("Invalid day entry. Please enter again.\n");
					flag = FALSE;
				} //if (data -> birthDate.day < 1 || data -> birthDate.day > 30)

				break;

			case 2:
				if (data -> birthDate.year % 4 == 0 && data -> birthDate.year % 400 == 0) {
					leapFlag = TRUE;
				} else if (data -> birthDate.year % 4 == 0 && data -> birthDate.year % 100 == 0) {
					leapFlag = FALSE;
				} else if (data -> birthDate.year % 4 == 0) {
					leapFlag = TRUE;
				} else {
					leapFlag = FALSE;
				} //End of exteneded if clause

				if (leapFlag == TRUE) {
					if (data -> birthDate.day < 1 || data -> birthDate.day > 29) {
						printf("Invalid day entry. Please enter again.\n");
						flag = FALSE;
					} //if (data -> birthDate.day < 1 || data -> birthDate.day > 29)
				} else if (leapFlag == FALSE) {
					if (data -> birthDate.day < 1 || data -> birthDate.day > 28) {
						printf("Invalid day entry. Please enter again.\n");
						flag = FALSE;
					} //if (data -> birthDate.day < 1 || data -> birthDate.day > 28)
				} //End of extended if clause

				break;
		} //switch (data -> birthDate.month)
	} while (flag == FALSE);

	printf("Enter the address: ");
	scanf("%c", & temp);
	gets(tempStr);

	data -> address = (string * ) malloc(strlen(tempStr) + 1);

	if (data -> address == NULL) {
		printf("Data allocation unsuccessful.\n");

		getch();
		exit(0);
	} //if (data -> address == NULL)

	strcpy(data -> address, tempStr);

	do {
		flag = TRUE;
		printf("Enter the phone number: ");
		gets(tempStr);

		data -> phoneNum = (string * ) malloc(strlen(tempStr) + 1);

		if (data -> phoneNum == NULL) {
			printf("Data allocation unsuccessful.\n");

			getch();
			exit(0);
		} //if (data -> phoneNum == NULL)

		strcpy(data -> phoneNum, tempStr);

		for (i = 0; * (data -> phoneNum + i) != '\0'; i++) {
			if (!isdigit( * (data -> phoneNum + i))) {
				printf("Invalid character %c entered.\n", * (data -> phoneNum + i));
				flag = FALSE;
			} //if (!isdigit( * (data -> phoneNum + i)))
		} //for (i = 0; * (data -> phoneNum + i) != '\0'; i++)
	} while (flag == FALSE);
} //void dataEntry(struct database * data)

//************************************************************************

void dataDisplay(struct database data) {
	printf("Name: %s\n", data.name);
	printf("Date of Birth: %d/%d/%d\n", data.birthDate.day, data.birthDate.month, data.birthDate.year);
	printf("Address: %s\n", data.address);
	printf("Phone Number: %s\n", data.phoneNum);
} //void dataDisplay(struct database data)