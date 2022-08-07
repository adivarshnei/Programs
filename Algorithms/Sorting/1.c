#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define ELEM_LIMIT 10

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void delay(int);
void swapVals(int*, int*);
void initArrayValues(int*);
void printArray(int*, int);
enum Bool isSorted(int*);
void barGraph(int*);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   static int array[ARRAY_SIZE] = { 0 };

   system("cls");

   initArrayValues(array);

   //Sorting Algorithm Here

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void delay( int sec ) {
	clock_t stTime = clock();

	while (clock() < stTime + sec) { }
}

void swapVals(int* val1, int* val2) {
   int temp;

   temp = *val1;
   *val1 = *val2;
   *val2 = temp;
}

void initArrayValues(int* array) {
   LoopVar i;

   srand(time(NULL));

   for (i = 0; i < ARRAY_SIZE; i++) {
      array[i] = rand() % ELEM_LIMIT;
   }
}

void printArray(int* array, int size) {
   LoopVar i;

   for (i = 0; i < size; i++) {
      printf("%-4d", array[i]);
   }
}

enum Bool isSorted(int* array) {
   LoopVar i;

   for (i = 0; i < ARRAY_SIZE - 1; i++) {
      if (array[i] > array[i + 1]) {
         return FALSE;
      }
   }

   return TRUE;
}

void barGraph(int a[ARRAY_SIZE]) {
   int max;
   LoopVar i, j;

   max = a[0];

   for (i = 1; i < ARRAY_SIZE; i++) {
      if (a[i] > max) {
         max = a[i];
      }
   }

   for (i = 0; i < max; i++) {
      for (j = 0; j < ARRAY_SIZE; j++) {
         if (a[j] >= max - i) {
            printf("*");
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }
}