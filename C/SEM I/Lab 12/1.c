/* WAP to read name and output ASCII list */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************

typedef unsigned int loopVar;
typedef char string;

//************************************************************************

int count = 0;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		string name[50];
		loopVar i;

		printf("Enter the name: ");
		scanf("%s", name);

		for (i = 0; name[i] != '\0'; i++) {
			printf("%c: %d\n", name[i], name[i]);
		} //for (i = 0; name[i] != '\0'; i++)

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

		count++;

		if (count >= 15) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		} //if (count >= 50) 
	} //while (rep == 1) 

	printf("Normal END\n");

	getch();
	return 0;
} //int main(void)