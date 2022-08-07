#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 //#include <alloc.h>
#include <math.h>
#include <string.h>

enum choice {
	READ = 1,
	WRITE,
	AVE,
	EXIT,
};

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

struct student {
	string * name;
	unsigned int roll_no;
	unsigned int marks;
};

struct indices {
	int data;
	int read;
};

void dataEntry(struct student * );
void dataDisplay(struct student);

int count = 0;
bufferClear temp;
string tempStr[50];

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		loopVar i;
		struct student stData[30];
		enum choice menuOption;
		struct indices index;
		float ave=0.0;

		index.data = 0;

		do {
			printf("1. Read Student Data\n");
			printf("2. Write Student Data\n");
			printf("3. Average\n");
			printf("4. Exit\n");
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
							}
						} while (index.read < 0 || index.read > index.data);
					}

					break;

				case WRITE:
					if (index.data >= 30) {
						printf("Overflow Error\n");
					} else {
						dataEntry( & stData[index.data]);
						index.data++;
					}

					break;

				case AVE:
					for(i=0; i<index.data; i++){
						ave+=stData[i].marks;
					}

					ave/=(index.data);

					printf("Average: %.2f\n", ave);

				case EXIT:
					break;

				default:
					printf("Invalid Entry. Please enter again.\n");
					getch();

					break;

			}
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

void dataEntry(struct student * stData) {
	printf("Enter the name: ");
	scanf("%s", tempStr);

	stData -> name = malloc(strlen(tempStr) + 1);
	strcpy(stData -> name, tempStr);

	printf("Enter the roll number: ");
	scanf("%d", & stData -> roll_no);

	printf("Enter the marks: ");
	scanf("%d", & stData -> marks);

	stData -> roll_no = abs(stData -> roll_no);
	stData -> marks = abs(stData -> marks);
}

void dataDisplay(struct student stData) {
	printf("Name: %s\n", stData.name);
	printf("Roll No: %d\n", stData.roll_no);
	printf("Marks: %d\n", stData.marks);
}