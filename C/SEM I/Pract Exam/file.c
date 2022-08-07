/* 
Name: Adersh Varshnei
Enrollment No: A2305220129
Program Number: 30 
Problem: Write a program in C to display the index of smallest and largest element in 10 integers. 
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//******************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;
typedef int intArr;

//******************************************************************

struct elemIndex {
	int small;
	int large;
}; //struct elemIndex

//******************************************************************

struct elemIndex indexFinder(intArr[10]);

//******************************************************************

int count = 0;
bufferClear temp;

//******************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		struct elemIndex indices;
		intArr arr[10];
		loopVar i;

		printf("Enter the ten integers: ");

		for (i = 0; i < 10; i++) {
			scanf("%d", & arr[i]);
		} //for (i = 0; i < 10; i++)

		indices = indexFinder(arr);

		printf("Smallest Element of array %d is at index %d\n", arr[indices.small], indices.small);
		printf("Largest Element of array %d is at index %d\n", arr[indices.large], indices.large);

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

//******************************************************************

struct elemIndex indexFinder(intArr arr[10]) {
	struct elemIndex indices;
	loopVar i;

	indices.small = 0;
	indices.large = 0;

	for (i = 0; i < 10; i++) {
		if (arr[i] < arr[indices.small]) {
			indices.small = i;
		} //if (arr[i] < arr[indices.small])

		if (arr[i] > arr[indices.large]) {
			indices.large = i;
		} //if (arr[i] > arr[indices.large])
	} //for (i = 0; i < 10; i++)

	return indices;
} //struct elemIndex indexFinder(intArr arr[10])