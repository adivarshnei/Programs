/* Write a program which will read a text and count all occurrences of a particular word */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//************************************************************************

enum boolFlag {
	FALSE = 0,
	TRUE
}; //enum boolFlag

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

//************************************************************************

void wordCounter(string * , string * );

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		string inputText[50];
		static string inputWord[10];

		printf("Enter the string: ");
		gets(inputText);

		printf("Enter the word to be found: ");
		gets(inputWord);

		wordCounter(inputText, inputWord);

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

void wordCounter(string text[50], string word[10]) {
	loopVar i = 0, j;
	enum boolFlag flag;
	string eval[10];
	unsigned int freq = 0;

	while (i < strlen(text)) {
		j = 0;
		flag = TRUE;

		while ( 
			* (text + i) != ' ' &&
			* (text + i) != '.' &&
			* (text + i) != ',' &&
			* (text + i) != ';' &&
			* (text + i) != ':' &&
			* (text + i) != '/' &&
			* (text + i) != '\0') {
			eval[j] = text[i];
			i++;
			j++;
		} //while ( 
		//	* (text + i) != ' ' &&
		//	* (text + i) != '.' &&
		//	* (text + i) != ',' &&
		//	* (text + i) != ';' &&
		//	* (text + i) != ':' &&
		//	* (text + i) != '/' &&
		//	* (text + i) != '\0')

		i++;
		eval[j] = '\0';

		if (strlen(word) == strlen(eval)) {
			for (j = 0; eval[j] != '\0' && word[j] != '\0'; j++) {
				if (eval[j] != word[j]) {
					flag = FALSE;
					break;
				} //if (eval[j] != word[j])
			} //for (j = 0; eval[j] != '\0' && word[j] != '\0'; j++)
		} else {
			flag = FALSE;
		} //End of extended if clause

		if (flag == TRUE) {
			freq++;
		} //if (flag == TRUE)
	} //while (i < strlen(text))

	printf("%s is present in given string %d times\n", word, freq);
} //void wordCounter(string text[50], string word[10])