// Write a menu driven program to implement following operations on
// Priority Queue:
// enqueue()
// dequeue()
// display()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define ELEM_LIMIT 20

typedef int LoopVar;
typedef char BufferClear;

enum Bool { TRUE = 1, FALSE = 0 };

struct Element {
   int element;
   int priority;
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

int getHighestPriority(struct Element queue[MAX_SIZE],
                       struct Locations location) {
   LoopVar i;
   int highestPriority;

   highestPriority = location.front;

   for (i = location.front; i <= location.rear; i++) {
      if (queue[highestPriority].priority < queue[i].priority) {
         highestPriority = i;
      }
   }

   return highestPriority;
}

void enqueue(struct Element queue[MAX_SIZE], struct Locations* location) {
   if (isFull(*location) == TRUE) {
      printf("Queue Overflow\n");
      return;
   }

   if (isInit(*location) == TRUE) {
      location->front++;
   }

   srand(time(NULL));

   location->rear++;
   queue[location->rear].element = rand() % (ELEM_LIMIT - 1) + 1;

   srand(time(NULL));
   srand(rand());

   queue[location->rear].priority = rand() * rand() % (ELEM_LIMIT - 1) + 1;

   printf("%d enqueued with priority %d\n", queue[location->rear].element,
          queue[location->rear].priority);

   return;
}

void dequeue(struct Element queue[MAX_SIZE], struct Locations* location) {
   int index;
   LoopVar i;

   if (isEmpty(*location) == TRUE) {
      printf("Queue Underflow\n");
      return;
   }

   index = getHighestPriority(queue, *location);

   printf("%d with priority %d dequeued\n", queue[index].element,
          queue[index].priority);

   for (i = index; i < location->rear; i++) {
      queue[i] = queue[i + 1];
   }

   location->rear--;
}

void display(struct Element queue[MAX_SIZE], struct Locations location) {
   LoopVar i;

   printf("Queue status (Element, Priority): ");

   for (i = 0; i < MAX_SIZE; i++) {
      if (i < location.front || i > location.rear) {
         printf("          ");
      } else {
         printf("(%d, %d)", queue[i].element, queue[i].priority);
      }
   }
}

int main(void) {
   static struct Element queue[MAX_SIZE];
   struct Locations location;
   int choice;

   initQueue(&location);

   system("cls");

   do {
      printf("\n1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Display\n");
      printf("4. Peek Highest Priority\n");
      printf("5. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

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
         if (isInit(location) == TRUE) {
            printf("Queue Underflow\n");
         } else {
            printf("Element with highestPriority: (%d, %d)",
                   queue[getHighestPriority(queue, location)].element,
                   queue[getHighestPriority(queue, location)].priority);
         }

         break;

      case 5:
         break;

      default:
         printf("Wrong Choice\n");
         break;
      }
   } while (choice != 5);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
