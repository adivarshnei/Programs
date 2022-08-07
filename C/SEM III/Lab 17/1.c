// Write a program to implement following sorting techniques:
// Merge sort
// Quick sort

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
   IntArr arr[ARRAY_SIZE];
};

struct Counters {
   int mergeCounter;
   int quickCounter;
};

BufferClear temp;
enum Bool shouldRepeat;
static struct Counters counter = {0, 0};

void initArray(struct Array* array) {
   LoopVar i;

   for (i = 0; i < ARRAY_SIZE; i++) {
      array->arr[i] = rand() % ELEM_LIMIT;
   }
}

void printArray(struct Array* array) {
   LoopVar i;

   for (i = 0; i < ARRAY_SIZE; i++) {
      printf("%-3d", array->arr[i]);
   }
}

void swap(int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void merge(IntArr array[ARRAY_SIZE], int low, int middle, int high) {
   LoopVar i, j, k;

   IntArr temp[ARRAY_SIZE];

   for (i = low; i <= high; i++) {
      temp[i] = array[i];
   }

   i = low;
   j = middle + 1;
   k = low;

   while (i <= middle && j <= high) {
      if (temp[i] <= temp[j]) {
         array[k++] = temp[i++];
      } else {
         array[k++] = temp[j++];
      }
   }

   while (i <= middle) {
      array[k++] = temp[i++];
   }
}

void mergeSort(struct Array* array, int low, int high) {
   if (low < high) {
      int middle = (low + high) / 2;
      mergeSort(array, low, middle);
      mergeSort(array, middle + 1, high);
      merge(array->arr, low, middle, high);

      counter.mergeCounter++;

      printf("\nAfter Pass %2d: ", counter.mergeCounter + 1);
      printArray(array);
   }
}

void mergeRef(struct Array array, int low, int high) {
   mergeSort(&array, low, high);
}

int partition(struct Array* array, int low, int high) {
   int pivot = array->arr[high];
   int pivotLoc = (low - 1);
   LoopVar j;

   for (j = low; j <= high - 1; j++) {
      if (array->arr[j] < pivot) {
         pivotLoc++;
         swap(&array->arr[pivotLoc], &array->arr[j]);
      }
   }

   swap(&array->arr[pivotLoc + 1], &array->arr[high]);
   return (pivotLoc + 1);
}

void quickSort(struct Array* array, int low, int high) {
   if (low < high) {
      int pivot = partition(array, low, high);

      counter.quickCounter++;

      printf("\nAfter Pass %2d: ", counter.quickCounter + 1);
      printArray(array);

      quickSort(array, low, pivot - 1);
      quickSort(array, pivot + 1, high);
   }
}

void quickRef(struct Array array, int low, int high) {
   quickSort(&array, low, high);
}

int main(void) {
   struct Array array;
   int choice;

   system("cls");
   srand(time(NULL));

   initArray(&array);
   printf("Base Array:\n");
   printArray(&array);

   do {
      printf("\n1. Merge Sort\n");
      printf("2. Quick Sort\n");
      printf("3. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         mergeRef(array, 0, ARRAY_SIZE - 1);
         break;

      case 2:
         quickRef(array, 0, ARRAY_SIZE - 1);
         break;

      case 3:
         break;

      default:
         printf("Wrong Choice.\n");
         break;
      }
   } while (choice != 3);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
