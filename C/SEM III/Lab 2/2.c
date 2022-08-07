// WAP to perform operations (insertion, deletion and traverse) on 1D array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LIMIT 15
#define ELEM_LIMIT 50

typedef unsigned int LoopVar;
typedef char BufferClear;
typedef int IntArr;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void initArray(IntArr*);
void printArray(IntArr*);
int linearSearch(IntArr*, int);
void insertion(IntArr*);
void insertAtBeg(IntArr*);
void insertAtIndex(IntArr*);
void insertAfterIndex(IntArr*);
void insertBeforeIndex(IntArr*);
void deletion(IntArr*);
void deleteByElement(IntArr*);
void deleteByIndex(IntArr*);
void traverse(IntArr*);

BufferClear temp;
enum Bool shouldRepeat;
int arraySize = 10;

int main(void) {
   IntArr array[ARRAY_LIMIT];
   int choice;

   system("cls");

   initArray(array);
   printf("Given Array: \n");
   printArray(array);

   do {
      printf("\n1. Insertion\n");
      printf("2. Deletion\n");
      printf("3. Traverse\n");
      printf("4. Print Array\n");
      printf("5. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);
      printf("\n");

      switch (choice) {
      case 1:
         insertion(array);
         break;

      case 2:
         deletion(array);
         break;

      case 3:
         traverse(array);
         break;

      case 4:
         printf("Array: \n");
         printArray(array);

         break;

      case 5:
         break;

      default:
         printf("Wrong choice\n");
         break;
      }
   } while (choice != 5);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void initArray(IntArr array[ARRAY_LIMIT]) {
   LoopVar i;

   srand(time(NULL));

   for (i = 0; i < arraySize; i++) {
      array[i] = rand() % ELEM_LIMIT;
   }
}

void printArray(IntArr array[ARRAY_LIMIT]) {
   LoopVar i;

   for (i = 0; i < arraySize; i++) {
      printf("%d\t", array[i]);
   }
}

int linearSearch(IntArr array[ARRAY_LIMIT], int element) {
   LoopVar i;

   for (i = 0; i < arraySize; i++) {
      if (array[i] == element) {
         return i;
      }
   }

   return -1;
}

void insertion(IntArr array[ARRAY_LIMIT]) {
   int choice;

   do {
      printf("\n1. Insert at Beginning of Array\n");
      printf("2. Insert at Index\n");
      printf("3. Insert before Index\n");
      printf("4. Insert after Index\n");
      printf("5. Back to Main Menu\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);
      printf("\n");

      switch (choice) {
      case 1:
         insertAtBeg(array);
         break;

      case 2:
         insertAtIndex(array);
         break;

      case 3:
         insertBeforeIndex(array);
         break;

      case 4:
         insertAfterIndex(array);
         break;

      case 5:
         break;

      default:
         printf("Wrong Choice\n");
         break;
      }
   } while (choice != 5);
}

void insertAtBeg(IntArr array[ARRAY_LIMIT]) {
   LoopVar i;
   int newElement;

   if (arraySize == ARRAY_LIMIT) {
      printf("Array is full\n");
      return;
   }

   arraySize++;

   for (i = arraySize - 1; i > 0; i--) {
      array[i] = array[i - 1];
   }

   printf("Enter new element: ");
   scanf("%d", &newElement);

   array[0] = newElement;

   printf("\nModified Array: ");
   printArray(array);
}

void insertAtIndex(IntArr array[ARRAY_LIMIT]) {
   LoopVar i;
   int newElement;
   int index;

   if (arraySize == ARRAY_LIMIT) {
      printf("Array is full\n");
      return;
   }

   printf("Enter index to enter new element at: ");
   scanf("%d", &index);

   if (index >= arraySize || index < 0) {
      printf("Invalid Index Entered\n");
      return;
   }

   arraySize++;

   for (i = arraySize - 1; i > index; i--) {
      array[i] = array[i - 1];
   }

   printf("Enter new element: ");
   scanf("%d", &newElement);

   array[index] = newElement;

   printf("\nModified Array: ");
   printArray(array);
}

void insertBeforeIndex(IntArr array[ARRAY_LIMIT]) {
   LoopVar i;
   int newElement;
   int index;

   if (arraySize == ARRAY_LIMIT) {
      printf("Array is full\n");
      return;
   }

   printf("Enter index to enter new element before: ");
   scanf("%d", &index);

   if (index >= arraySize + 1 || index < 1) {
      printf("Invalid Index Entered\n");
      return;
   }

   arraySize++;

   if (index >= arraySize) {
      printf("Invalid Index Entered\n");
      return;
   }

   for (i = arraySize - 1; i > index - 1; i--) {
      array[i] = array[i - 1];
   }

   printf("Enter new element: ");
   scanf("%d", &newElement);

   array[index - 1] = newElement;

   printf("\nModified Array: ");
   printArray(array);
}

void insertAfterIndex(IntArr array[ARRAY_LIMIT]) {
   LoopVar i;
   int newElement;
   int index;

   if (arraySize == ARRAY_LIMIT) {
      printf("Array is full\n");
      return;
   }

   printf("Enter index to enter new element after: ");
   scanf("%d", &index);

   if (index >= arraySize || index < -1) {
      printf("Invalid Index Entered\n");
      return;
   }

   arraySize++;

   for (i = arraySize - 1; i > index + 1; i--) {
      array[i] = array[i - 1];
   }

   printf("Enter new element: ");
   scanf("%d", &newElement);

   array[index + 1] = newElement;

   printf("\nModified Array: ");
   printArray(array);
}

void deletion(IntArr array[ARRAY_LIMIT]) {
   int choice;

   do {
      printf("\n1. Delete by Element\n");
      printf("2. Delete by Index\n");
      printf("3. Back to Main Menu\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);
      printf("\n");

      switch (choice) {
      case 1:
         deleteByElement(array);
         break;

      case 2:
         deleteByIndex(array);
         break;

      case 3:
         break;

      default:
         printf("Wrong Choice\n");
         break;
      }
   } while (choice != 3);
}

void deleteByElement(IntArr array[ARRAY_LIMIT]) {
   int element;
   int index;
   LoopVar i;

   if (arraySize == 0) {
      printf("Array is empty\n");
      return;
   }

   printf("Enter element to delete: ");
   scanf("%d", &element);

   index = linearSearch(array, element);

   if (index == -1) {
      printf("Element not found in array\n");
      return;
   }

   arraySize--;

   for (i = index; i < arraySize + 1; i++) {
      array[i] = array[i + 1];
   }

   printf("\nModified Array: ");
   printArray(array);
}

void deleteByIndex(IntArr array[ARRAY_LIMIT]) {
   int index;
   LoopVar i;

   if (arraySize == 0) {
      printf("Array is empty\n");
      return;
   }

   printf("Enter index to delete element from: ");
   scanf("%d", &index);

   if (index < 0 || index >= arraySize) {
      printf("Invalid Index Entered\n");
      return;
   }

   arraySize--;

   for (i = index; i < arraySize + 1; i++) {
      array[i] = array[i + 1];
   }

   printf("\nModified Array: ");
   printArray(array);
}

void traverse(IntArr array[ARRAY_LIMIT]) {
   LoopVar i;

   if (arraySize == 0) {
      printf("Array is empty\n");
      return;
   }

   for (i = 0; i < arraySize; i++) {
      printf("Element at index %d: %d\n", i, array[i]);
   }
}
