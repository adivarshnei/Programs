// Write a menu driven program to implement following operations on Double Ended
// Queue:
// enqueue() [at front/rear]
// dequeue() [at front/rear]
// display()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define ELEM_LIMIT 20

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool { TRUE = 1, FALSE = 0 };

struct Locations {
   int front;
   int rear
};

BufferClear temp;
enum Bool shouldRepeat;

enum Bool isFull(struct Locations location) {
   if (location.rear == MAX_SIZE - 1) {
      return TRUE;
   } else {
      return FALSE;
   }
}

void enqueueFront(int queue[MAX_SIZE], struct Locations* location) {
   if (isFull(*location) == TRUE) {
      printf("Queue Overflow\n");
      return;
   }

   location->rear = location->rear + 1;
   location->front = location->front + 1;

   queue[location->front] = rand() % (ELEM_LIMIT - 1) + 1;

   printf("%d enqueued at front\n", queue[location->rear]);
}

void enqueueRear(int queue[MAX_SIZE], struct Locations* location) {
   if (isFull(*location) == TRUE) {
      printf("Queue Overflow\n");
      return;
   }

   if (isInit(*location) == TRUE) {
      location->front = location->front + 1;
   }

   location->rear++;
   queue[location->rear] = rand() % (ELEM_LIMIT - 1) + 1;
   printf("%d enqueued\n", queue[location->rear]);

   return;
}

int main(void) {
   // Variable Definitions

   system("cls");
   srand(time(NULL));

   // Program Body

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
