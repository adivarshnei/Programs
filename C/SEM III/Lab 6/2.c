// Write a menu driven program to implement following operations on Circular Queue
// enqueue()
// dequeue()
// display()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5
#define ELEM_LIMIT 20

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

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
   if (location.front == -1 && location.rear == -1) {
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

enum Bool isFull(struct Locations location) {
   if ((location.rear + 1) % MAX_SIZE == location.front) {
      return TRUE;
   } else {
      return FALSE;
   }
}

void enqueue(int queue[MAX_SIZE], struct Locations* location) {
   if (isFull(*location) == TRUE) {
      printf("Queue Overflow\n");
      return;
   }

   if (isInit(*location) == TRUE) {
      location->front = location->front + 1;
   }

   location->rear = (location->rear + 1) % MAX_SIZE;
   queue[location->rear] = rand() % (ELEM_LIMIT - 1) + 1;
   printf("%d enqueued\n", queue[location->rear]);

   return;
}

void dequeue(int queue[MAX_SIZE], struct Locations* location) {
   if (isInit(*location) == TRUE) {
      printf("Queue Underflow\n");
      return;
   }

   printf("%d dequeued\n", queue[location->front]);

   if (isEmpty(*location) == TRUE) {
      initQueue(location);
      return;
   }

   location->front = (location->front + 1) % MAX_SIZE;
}

void display(int queue[MAX_SIZE], struct Locations location) {
   LoopVar i;

   printf("Queue Status: ");

   for (i = 0; i < MAX_SIZE; i++) {
      if (location.rear < location.front) {
         if (i < location.front && i > location.rear) {
            printf("   ");
         } else {
            printf("%3d", queue[i]);
         }
      } else {
         if (i < location.front || i > location.rear) {
            printf("   ");
         } else {
            printf("%3d", queue[i]);
         }
      }
   }
}

int main(void) {
   static int queue[MAX_SIZE];
   struct Locations location;
   int choice;

   initQueue(&location);

   system("cls");

   do {
      printf("\n1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      // system("cls");

      switch (choice) {
      case 1:
         enqueue(queue, &location);
         display(queue, location);
         break;

      case 2:
         dequeue(queue, &location);
         display(queue, location);
         break;

      case 3:
         display(queue, location);
         break;

      case 4:
         break;

      default:
         printf("Wrong Choice\n");
         break;
      }
   } while (choice != 4);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
