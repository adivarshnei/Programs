// Write a program to merge 2 arrays into one array and display

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEM_LIMIT 50

typedef unsigned int LoopVar;
typedef char BufferClear;
typedef int intArr;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

struct Array {
   int size;
   intArr* array;
};

void initArrays(struct Array*, struct Array*);
void printArray(struct Array);
void mergeArray(struct Array*, struct Array, struct Array);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   struct Array a1;
   struct Array a2;
   struct Array merged;

   system("cls");

   printf("Enter size of array 1: ");
   scanf("%d", &a1.size);
   printf("Enter size of array 2: ");
   scanf("%d", &a2.size);

   merged.size = a1.size + a2.size;

   a1.array = (intArr*) malloc(a1.size * sizeof(int));
   a2.array = (intArr*) malloc(a2.size * sizeof(int));
   merged.array = (intArr*) malloc(merged.size * sizeof(int));

   if (a1.array == NULL || a2.array == NULL || merged.array == NULL) {
      printf("Data allocation failed\n");

      exit(0);
   }

   initArrays(&a1, &a2);

   mergeArray(&merged, a1, a2);

   printf("Array 1: \n");
   printArray(a1);

   printf("Array 2: \n");
   printArray(a2);

   printf("Array 3: \n");
   printArray(merged);

   free(a1.array);
   free(a2.array);
   free(merged.array);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void initArrays(struct Array* a1, struct Array* a2) {
   LoopVar i;

   srand(time(NULL));

   for (i = 0; i < a1->size; i++) {
      a1->array[i] = rand() % ELEM_LIMIT;
   }
   for (i = 0; i < a2->size; i++) {
      a2->array[i] = rand() % ELEM_LIMIT;
   }

   return;
}

void printArray(struct Array a) {
   LoopVar i;

   for (i = 0; i < a.size; i++) {
      printf("%-4d", a.array[i]);
   }

   printf("\n");
}

void mergeArray(struct Array* merged, struct Array a1, struct Array a2) {
   LoopVar i;

   for (i = 0; i < a1.size; i++) {
      merged->array[i] = a1.array[i];
   }
   for (; i < merged->size; i++) {
      merged->array[i] = a2.array[i - a1.size];
   }
}