// Write a program to implement queue operations (enqueue, dequeue, display)
// using singly linked list

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEM_LIMIT 10

typedef int LoopVar;
typedef char BufferClear;

enum Bool { TRUE = 1, FALSE = 0 };

struct Node {
   int data;
   struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

BufferClear temp;
enum Bool shouldRepeat;

void display() {
   struct Node* temp = front;

   if (temp == NULL) {
      printf("Queue is Empty\n");
      return;
   }

   printf("\n%d", temp->data);
   temp = temp->next;

   while (temp != NULL) {
      printf("->%d", temp->data);
      temp = temp->next;
   }

   printf("\n");
}

void enqueue() {
   struct Node* newNode;
   int element;

   newNode = (struct Node*) malloc(sizeof(struct Node));

   element = rand() % (ELEM_LIMIT - 1) + 1;
   newNode->data = element;
   newNode->next = NULL;

   if (front == NULL) {
      front = newNode;
      rear = newNode;
   } else {
      rear->next = newNode;
      rear = newNode;
   }

   printf("%d enqueued\n", newNode->data);
   display();
}

void dequeue() {
   struct Node* temp;

   if (front == NULL) {
      printf("Queue not initialized, cannot delete\n");

      return;
   }

   printf("%d deleted from list\n", front->data);

   temp = front;
   front = front->next;

   if (front == NULL) {
      rear = NULL;
   }

   free(temp);

   display();
}

int main(void) {
   int choice;

   system("cls");
   srand(time(NULL));

   do {
      printf("\n1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         enqueue();
         break;

      case 2:
         dequeue();
         break;

      case 3:
         display();

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
