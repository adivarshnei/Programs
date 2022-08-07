// You have been given a pack of cards (Only Spades) numbered 1 to
// 13 (Ace, 2 to 10, Jack Queen, King) in random order. Write a program
// to sort these cards. Use Bubble sort and print each line of output
// after every iteration.
//
// For the same above problem, Write the program using Insertion sort
// and print each line of output after every iteration.
//
// Compare the number of steps for each sorting technique

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 13

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

typedef int LoopVar;
typedef char BufferClear;

enum Bool { TRUE = 1, FALSE = 0 };

struct Array {
   int array[ARRAY_SIZE];
};

BufferClear temp;
enum Bool shouldRepeat;

void printArray(int* array) {
   LoopVar i;

   for (i = 0; i < ARRAY_SIZE; i++) {
      switch (array[i]) {
      case ACE:
         printf("  A");
         break;

      case JACK:
         printf("  J");
         break;

      case QUEEN:
         printf("  Q");
         break;

      case KING:
         printf("  K");
         break;

      default:
         printf("%3d", array[i]);
         break;
      }
   }

   printf("\n");
}

void swap(int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void shuffle(int* array) {
   LoopVar i, j;
   int t;

   for (i = 0; i < ARRAY_SIZE; i++) {
      j = rand() % ARRAY_SIZE;
      swap(&array[i], &array[j]);
   }
}

void bubbleSort(struct Array cards) {
   LoopVar i, j;
   int stepCount = 0;

   for (i = 0; i < ARRAY_SIZE - 1; i++) {
      for (j = 0; j < ARRAY_SIZE - 1 - i; j++) {
         if (cards.array[j] > cards.array[j + 1]) {
            swap(&cards.array[j], &cards.array[j + 1]);
         }

         stepCount++;
      }

      printf("After Pass %2d: ", i + 1);
      printArray(cards.array);
   }

   printf("Steps Taken: %d", stepCount);
}

void insertionSort(struct Array cards) {
   LoopVar i, j;
   int element;
   int stepCount = 0;

   for (i = 1; i < ARRAY_SIZE; i++) {
      element = cards.array[i];
      j = i - 1;

      while (j >= 0 && cards.array[j] > element) {
         cards.array[j + 1] = cards.array[j];
         j--;
         stepCount++;
      }

      cards.array[j + 1] = element;

      printf("After Pass %2d: ", i);
      printArray(cards.array);
   }

   printf("Steps Taken: %d", stepCount);
}

int main(void) {
   struct Array cards = {{ACE, 2, 3, 4, 5, 6, 7, 8, 9, 10, JACK, QUEEN, KING}};
   system("cls");

   srand(time(NULL));

   shuffle(cards.array);

   printf("Original Array: \n");
   printArray(cards.array);

   printf("\nBubble Sort:\n");
   bubbleSort(cards);

   printf("\n\nInsertion Sort:\n");
   insertionSort(cards);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
