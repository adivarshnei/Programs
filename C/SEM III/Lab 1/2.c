// Program to implement linear search in 2D array

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

struct Location {
   int row;
   int col;
};

void initArray(IntArr[][ARRAY_SIZE]);
void printArray(IntArr[][ARRAY_SIZE]);
struct Location linearSearch(IntArr[][ARRAY_SIZE], int);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   IntArr array[ARRAY_SIZE][ARRAY_SIZE];
   int element;
   struct Location loc;

   system("cls");

   initArray(array);
   printf("Given Array: \n");
   printArray(array);

   printf("\nEnter element to be found: ");
   scanf("%d", &element);

   loc = linearSearch(array, element);

   (loc.row == -1) ?
      printf("%d not found", element) :
      printf("%d found at index [%d][%d]", element, loc.row, loc.col);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void initArray(IntArr array[][ARRAY_SIZE]) {
   LoopVar i, j;

   srand(time(NULL));

   for (i = 0; i < ARRAY_SIZE; i++) {
      for (j = 0; j < ARRAY_SIZE; j++) {
         array[i][j] = rand() % ELEM_LIMIT;
      }
   }
}

void printArray(IntArr array[][ARRAY_SIZE]) {
   LoopVar i, j;

   for (i = 0; i < ARRAY_SIZE; i++) {
      for (j = 0; j < ARRAY_SIZE; j++) {
         printf("%d\t", array[i][j]);
      }
      printf("\n");
   }
}

struct Location linearSearch(IntArr array[][ARRAY_SIZE], int element) {
   LoopVar i, j;
   struct Location loc;

   for (i = 0; i < ARRAY_SIZE; i++) {
      for (j = 0; j < ARRAY_SIZE; j++) {
         if (array[i][j] == element) {
            loc.row = i;
            loc.col = j;
            return loc;
         }
      }
   }

   loc.row = -1;
   loc.col = -1;

   return loc;
}