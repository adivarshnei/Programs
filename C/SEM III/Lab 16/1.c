// Write a program to implement following sorting techniques:
// Bubble Sort
// Insertion Sort
// Selection Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20
#define ELEM_LIMIT 50

typedef int LoopVar;
typedef int IntArr;
typedef char BufferClear;

enum Bool { TRUE = 1, FALSE = 0 };

struct Array {
   int arr[ARRAY_SIZE];
};

BufferClear temp;
enum Bool shouldRepeat;

void initArray(struct Array* array) {
   LoopVar i;

   for (i = 0; i < ARRAY_SIZE; i++) {
      array->arr[i] = rand() % ELEM_LIMIT;
   }
}

void printArray(struct Array array) {
   LoopVar i;

   for (i = 0; i < ARRAY_SIZE; i++) {
      printf("%-3d", array.arr[i]);
   }
}

void swap(int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void bubbleSort(struct Array array) {
   LoopVar i, j;

   for (i = 0; i < ARRAY_SIZE - 1; i++) {
      for (j = 0; j < ARRAY_SIZE - 1 - i; j++) {
         if (array.arr[j] > array.arr[j + 1]) {
            swap(&array.arr[j], &array.arr[j + 1]);
         }
      }

      printf("\nAfter Pass %2d: ", i + 1);
      printArray(array);
   }
}

void selectionSort(struct Array array) {
   LoopVar i, j;
   int minIndex;

   for (i = 0; i < ARRAY_SIZE; i++) {
      minIndex = i;

      for (j = i + 1; j < ARRAY_SIZE; j++) {
         if (array.arr[j] < array.arr[minIndex]) {
            minIndex = j;
         }
      }

      swap(&array.arr[minIndex], &array.arr[i]);

      printf("\nAfter Pass %2d: ", i + 1);
      printArray(array);
   }
}

void insertionSort(struct Array array) {
   LoopVar i, j;
   int element;

   for (i = 1; i < ARRAY_SIZE; i++) {
      element = array.arr[i];
      j = i - 1;

      while (j >= 0 && array.arr[j] > element) {
         array.arr[j + 1] = array.arr[j];
         j--;
      }

      array.arr[j + 1] = element;

      printf("\nAfter Pass %2d: ", i);
      printArray(array);
   }
}

int main(void) {
   struct Array array;
   int choice;

   system("cls");
   srand(time(NULL));

   initArray(&array);
   printf("Base Array:\n");
   printArray(array);

   do {
      printf("\n1. Bubble Sort\n");
      printf("2. Selection Sort\n");
      printf("3. Insertion Sort\n");
      printf("4. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         bubbleSort(array);
         break;

      case 2:
         selectionSort(array);
         break;

      case 3:
         insertionSort(array);
         break;

      case 4:
         break;

      default:
         printf("Wrong Choice.\n");
         break;
      }
   } while (choice != 4);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
