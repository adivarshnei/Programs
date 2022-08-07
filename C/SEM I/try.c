#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void display(int ** element, int num1, int num2) {
	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num2; j++) {
			printf("\nEnter the content of the array of element[%d][%d]", i, j);
			scanf("%d", &element[i][j]);
		}

	}
	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num2; j++) {
			printf("\nthe value of the content of the array of element[%d][%d] is %d", i, j, element[i][j]);
		}

	}
}

int main() {
	int num1, num2;
	int ** element;
	int i;

	printf("Enter the no of element and sub type:");
	scanf("%d %d", & num1, & num2);

	element = (int ** ) malloc(num1 * sizeof(int * ));

	if (element == NULL) {
		printf("Data allocation unsuccessful.\n");

		getch();
		exit(0);
	}

	for (i = 0; i < num1; i++) {
      element[i] = (int * ) malloc(num2 * sizeof(int));

		if (element[i] == NULL) {
			printf("Data allocation unsuccessful.\n");

			getch();
			exit(0);
		}
	}

	display(element, num1, num2);
	return 0;
}

// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>
// #include <ctype.h>

// enum orderFlag {
// 	INORDER = 1,
// 	NOTINORDER = 2
// };

// typedef unsigned int loopVar;
// typedef char bufferClear;

// void swap(int * , int * );
// void randArrToFile();
// void bubSort();
// void quickSort();
// void selSort();
// void mergeSort();
// void insSort();
// void heapSort();

// int count = 0;
// bufferClear temp;

// int main(void) {
// 	loopVar rep = 1;

// 	while (rep == 1) {
// 		randArrToFile();
// 		//bubSort();
// 		//quickSort();
// 		getch();

// 		printf("\nRepeat Program?: ");
// 		scanf("%d", & rep);
// 		scanf("%c", & temp);

// 		count++;

// 		if (count >= 15) {
// 			printf("Abnormal END\n");

// 			getch();
// 			exit(0);
// 		} //if (count >= 15) 
// 	} //while (rep == 1) 

// 	printf("Normal END\n");

// 	getch();
// 	return 0;
// } //int main(void)

// void swap(int * a, int * b) {
// 	int temp;

// 	temp = * b;
// 	* b = * a;
// 	* a = temp;
// }

// void randArrToFile() {
// 	loopVar i;
// 	int arr[10];
// 	FILE * f1;

// 	f1 = fopen("filetry.txt", "w");

// 	if (f1 == NULL) {
// 		printf("File opening unsuccessful. Exiting Program");

// 		getch();
// 		exit(0);
// 	}

// 	for (i = 0; i < 10; i++) {
// 		arr[i] = rand() % 100 + 1;
// 	}

// 	for (i = 0; i < 10; i++) {
// 		fprintf(f1, "%d ", arr[i]);
// 	}

// 	fprintf(f1, "\n");

// 	fclose(f1);
// }

// void bubSort() {
// 	loopVar i, j;
// 	int arr[10];
// 	FILE * f1;
// 	int arrIndex = 0;
// 	enum orderFlag orderChk = NOTINORDER;

// 	f1 = fopen("filetry.txt", "r");

// 	if (f1 == NULL) {
// 		printf("File opening unsuccessful. Exiting Program");

// 		getch();
// 		exit(0);
// 	}

// 	for (i = 0; i < 10; i++) {
// 		fscanf(f1, "%d", & arr[i]);
// 	}

// 	fclose(f1);

// 	while (orderChk != INORDER) {
// 		orderChk = INORDER;

// 		for (i = 0; i < 9; i++) {
// 			for (j = 0; j < 9 - j; j++) {
// 				if (arr[i] > arr[i + 1]) {
// 					swap( & arr[i], & arr[i + 1]);
// 					orderChk = NOTINORDER;
// 				}
// 			}
// 		}

// 		f1 = fopen("filetry.txt", "a");

// 		for (i = 0; i < 10; i++) {
// 			fprintf(f1, "%d ", arr[i]);
// 		}

// 		fprintf(f1, "\n");

// 		fclose(f1);
// 	}
// }

// void quickSort(){
// 	loopVar i, j;
// 	int arr[10];
// 	FILE * f1;
// 	int arrIndex = 0;
// 	enum orderFlag orderChk = NOTINORDER;

// 	f1 = fopen("filetry.txt", "r");

// 	if (f1 == NULL) {
// 		printf("File opening unsuccessful. Exiting Program");

// 		getch();
// 		exit(0);
// 	}

// 	for (i = 0; i < 10; i++) {
// 		fscanf(f1, "%d", & arr[i]);
// 	}

// 	fclose(f1);

// 	f1 = fopen("filetry.txt", "a");

// 	for (i = 0; i < 10; i++){
// 		fprintf(f1, "%d ", arr[i]);
// 	}

// 	fclose(f1);
// }