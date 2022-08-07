// WAP to search an element in an array using binary search

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define ELEM_LIMIT 50

typedef unsigned int LoopVar;
typedef char BufferClear;
typedef int IntArr;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void initArray(IntArr*);
void sortArray(IntArr*);
void printArray(IntArr*);
int binarySearch(IntArr*, int);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   IntArr array[ARRAY_SIZE];
   int element;
   int index;

   initArray(array);
   sortArray(array);
   printf("Given Array: \n");
   printArray(array);

   printf("\nEnter the element to be found: ");
   scanf("%d", &element);

   index = binarySearch(array, element);

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

void sortArray(IntArr array[ARRAY_SIZE]) {
   LoopVar i, j;
   int temp;

   for (i = 0; i < ARRAY_SIZE; i++) {
      for (j = 0; j < ARRAY_SIZE - 1 - i; j++) {
         if (array[j] > array[j + 1]) {
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
         }
      }
   }
}

void printArray(IntArr array[ARRAY_SIZE]) {
   LoopVar i;

   for (i = 0; i < ARRAY_SIZE; i++) {
      printf("%d\t", array[i]);
   }
}

int binarySearch(IntArr array[ARRAY_SIZE], int element) {
   int mid;
   int foundAtIndex = -1;
   int low = 0;
   int high = ARRAY_SIZE - 1;

   while (low <= high && foundAtIndex == -1) {
      mid = (low + high) / 2;

      if (element == array[mid]) {
         foundAtIndex = mid;
         return foundAtIndex;
      } else if (element > array[mid]) {
         low = mid + 1;
      } else {
         high = mid - 1;
      }
   }

   return foundAtIndex; // -1 means element not found
}