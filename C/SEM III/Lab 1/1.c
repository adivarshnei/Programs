// Program to implement linear search in 1D array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define ELEM_LIMIT 50

typedef unsigned int LoopVar;
typedef int IntArr;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void initArray(IntArr*);
void printArray(IntArr*);
int linearSearch(IntArr*, int);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   IntArr array[ARRAY_SIZE];// = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
   int element;
   int index;

   system("cls");

   initArray(array);
   printf("Given Array: \n");
   printArray(array);

   printf("\nEnter element to be found: ");
   scanf("%d", &element);

   index = linearSearch(array, element);

   (index == -1) ?
      printf("%d not found", element) :
      printf("%d found at index %d", element, index);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void initArray(IntArr array[ARRAY_SIZE]) {
   LoopVar i;

   srand(time(NULL));

   for (i = 0; i < ARRAY_SIZE; i++) {
      array[i] = rand() % ELEM_LIMIT;
   }
}

void printArray(IntArr array[]) {
   LoopVar i;

   for (i = 0; i < ARRAY_SIZE; i++) {
      printf("%d\t", array[i]);
   }
}

int linearSearch(IntArr array[], int element) {
   LoopVar i;

   for (i = 0; i < ARRAY_SIZE; i++) {
      if (array[i] == element) {
         return i;
      }
   }

   return -1;
}