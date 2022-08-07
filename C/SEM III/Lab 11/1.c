// Write a program to implement stack operations (push, pop, display) using
// singly linked list

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

struct Node* top = NULL;

BufferClear temp;
enum Bool shouldRepeat;

void display() {
   struct Node* temp = top;

   if (temp == NULL) {
      printf("Stack is Empty\n");
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

void push() {
   struct Node* newNode;
   int element;

   newNode = (struct Node*) malloc(sizeof(struct Node));

   element = rand() % (ELEM_LIMIT - 1) + 1;
   newNode->data = element;
   newNode->next = NULL;

   if (top == NULL) {
      top = newNode;
   } else {
      newNode->next = top;
      top = newNode;
   }

   printf("%d pushed onto stack\n", newNode->data);
   display();
}

void pop() {
   struct Node* temp;

   if (top == NULL) {
      printf("Stack underflow\n");

      return;
   }

   printf("%d popped from stack\n", top->data);

   temp = top;
   top = top->next;

   free(temp);

   display();
}

int main(void) {
   int choice;

   system("cls");
   srand(time(NULL));

   do {
      printf("\n1. Push\n");
      printf("2. Pop\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         push();
         break;

      case 2:
         pop();
         break;

      case 3:
         display();
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
