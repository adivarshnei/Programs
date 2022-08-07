// Write a menu driven program to implement following operations on Double
// Ended Queue:
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
   int rear;
};

BufferClear temp;
enum Bool shouldRepeat;

enum Bool initQueue(struct Locations* location) {
   location->front = -1;
   location->rear = -1;
}

enum Bool isInit(struct Locations location) {
   if (location.front == -1 && location.front == -1) {
      return TRUE;
   } else {
      return FALSE;
   }
}

enum Bool isEmpty(struct Locations location) {
   if (location.front == location.rear) {
      return TRUE;
   } else {
      return FALSE;
   }
}

enum Bool isFrontFull(struct Locations location) {
   if (location.front == 0) {
      return TRUE;
   } else {
      return FALSE;
   }
}

enum Bool isRearFull(struct Locations location) {
   if (location.rear == MAX_SIZE - 1) {
      return TRUE;
   } else {
      return FALSE;
   }
}

void enqueueFront(int queue[MAX_SIZE], struct Locations* location) {
   if (isFrontFull(*location) == TRUE) {
      printf("Queue Overflow\n");
      return;
   }

   if (isInit(*location) == TRUE) {
      location->front = location->front + 1;
      location->rear = location->rear + 1;
   } else {
      location->front = location->front - 1;
   }

   queue[location->front] = rand() % (ELEM_LIMIT - 1) + 1;
   printf("%d enqueued at front\n", queue[location->front]);

   return;
}

void enqueueRear(int queue[MAX_SIZE], struct Locations* location) {
   if (isRearFull(*location) == TRUE) {
      printf("Queue Overflow\n");
      return;
   }

   if (isInit(*location) == TRUE) {
      location->front = location->front + 1;
   }

   location->rear = location->rear + 1;
   queue[location->rear] = rand() % (ELEM_LIMIT - 1) + 1;
   printf("%d enqueued at rear\n", queue[location->rear]);

   return;
}

void dequeueFront(int queue[MAX_SIZE], struct Locations* location) {
   if (isInit(*location) == TRUE) {
      printf("Queue Underflow\n");
      return;
   }

   printf("%d dequeued\n", queue[location->front]);

   if (isEmpty(*location) == TRUE) {
      initQueue(location);
      return;
   }

   location->front++;

   return;
}

void dequeueRear(int queue[MAX_SIZE], struct Locations* location) {
   if (isInit(*location) == TRUE) {
      printf("Queue Underflow\n");
      return;
   }

   printf("%d dequeued\n", queue[location->rear]);

   if (isEmpty(*location) == TRUE) {
      initQueue(location);
      return;
   }

   location->rear--;
}

void display(int queue[MAX_SIZE], struct Locations location) {
   LoopVar i;

   printf("Queue status: ");

   for (i = 0; i < MAX_SIZE; i++) {
      if (i < location.front || i > location.rear) {
         printf("   ");
      } else {
         printf("%3d", queue[i]);
      }
   }
}

int main(void) {
   static int queue[MAX_SIZE];
   struct Locations location;
   int choice;

   initQueue(&location);

   system("cls");
   srand(time(NULL));

   do {
      printf("\n1. Enqueue to Front\n");
      printf("2. Enqueue to Rear\n");
      printf("3. Dequeue from Front\n");
      printf("4. Dequeue from Rear\n");
      printf("5. Display\n");
      printf("6. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         enqueueFront(queue, &location);
         display(queue, location);
         break;

      case 2:
         enqueueRear(queue, &location);
         display(queue, location);
         break;

      case 3:
         dequeueFront(queue, &location);
         display(queue, location);
         break;

      case 4:
         dequeueRear(queue, &location);
         display(queue, location);
         break;

      case 5:
         display(queue, location);
         break;

      case 6:
         break;

      default:
         printf("Wrong Choice\n");
         break;
      }
   } while (choice != 6);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
