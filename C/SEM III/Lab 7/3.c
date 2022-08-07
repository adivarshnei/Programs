// Write a menu driven program to implement following operations on Multiple
// Queue:
// enqueue() [to Queue1 and Queue2]
// dequeue() [from Queue1 and Queue2]
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
   if (location.front == -1 && location.rear == -1) {
      return TRUE;
   } else {
      return FALSE;
   }
}

enum Bool isEmpty(struct Locations location) {
   if (location.front < 0 || location.front > location.rear) {
      return TRUE;
   } else {
      return FALSE;
   }
}

enum Bool isFull(struct Locations location) {
   if (location.rear == MAX_SIZE - 1) {
      return TRUE;
   } else {
      return FALSE;
   }
}

void enqueue(int queue[MAX_SIZE], struct Locations* location, int whichQueue) {
   if (isFull(*location) == TRUE) {
      if (whichQueue == 1) {
         printf("Queue 1 Overflow");
      } else if (whichQueue == 2) {
         printf("Queue 2 Overflow");
      }

      return;
   }

   if (isInit(*location) == TRUE) {
      location->front = location->front + 1;
   }

   location->rear = location->rear + 1;
   queue[location->rear] = rand() % (ELEM_LIMIT - 1) + 1;
   printf("%d enqueued\n", queue[location->rear]);

   return;
}

void dequeue(int queue[MAX_SIZE], struct Locations* location, int whichQueue) {
   if (isEmpty(*location) == TRUE) {
      if (whichQueue == 1) {
         printf("Queue 1 Underflow\n");
      } else if (whichQueue == 2) {
         printf("Queue 2 Underflow\n");
      }

      return;
   }

   printf("%d dequeued\n", queue[location->front]);

   location->front = location->front + 1;

   return;
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
   static int queue1[MAX_SIZE];
   struct Locations location1;

   static int queue2[MAX_SIZE];
   struct Locations location2;

   int choice;

   initQueue(&location1);
   initQueue(&location2);

   system("cls");
   srand(time(NULL));

   do {
      printf("\n1. Enqueue to Queue 1\n");
      printf("2. Enqueue to Queue 2\n");
      printf("3. Dequeue from Queue 1\n");
      printf("4. Dequeue from Queue 2\n");
      printf("5. Display Queue 1\n");
      printf("6. Display Queue 2\n");
      printf("7. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         enqueue(queue1, &location1, 1);
         display(queue1, location1);
         break;

      case 2:
         enqueue(queue2, &location2, 2);
         display(queue2, location2);
         break;

      case 3:
         dequeue(queue1, &location1, 1);
         display(queue1, location1);
         break;

      case 4:
         dequeue(queue2, &location2, 2);
         display(queue2, location2);
         break;

      case 5:
         display(queue1, location1);
         break;

      case 6:
         display(queue2, location2);
         break;

      case 7:
         break;

      default:
         printf("Wrong Choice\n");
         break;
      }
   } while (choice != 7);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
