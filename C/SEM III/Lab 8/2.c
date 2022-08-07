// Write a program to reverse a single linked list

#include <stdio.h>
#include <stdlib.h>

#define ELEM_LIMIT 15

typedef int LoopVar;
typedef char BufferClear;

enum Bool { TRUE = 1, FALSE = 0 };

struct Node {
   int data;
   struct Node* next;
};

struct Node* start;

BufferClear temp;
enum Bool shouldRepeat;

void display() {
   struct Node* temp = start;

   if (temp == NULL) {
      printf("\nNo Elements in list\n");
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

void createList(int length) {
   struct Node* newNode;
   struct Node* temp = start;
   enum Bool choice;
   LoopVar i;

   for (i = 0; i < length; i++) {
      newNode = (struct Node*) malloc(sizeof(struct Node));

      newNode->data = rand() % (ELEM_LIMIT - 1) + 1;
      newNode->next = NULL;

      if (start == NULL) {
         start = newNode;
      } else {
         while (temp->next != NULL) {
            temp = temp->next;
         }

         temp->next = newNode;
      }

      temp = start;
   }
}

long int returnListLength() {
   long int listLength = 0;
   struct Node* temp = start;

   while (temp != NULL) {
      listLength++;
      temp = temp->next;
   }

   return listLength;
}

void reverseList() {
   struct Node** stack;
   struct Node* temp = start;
   long int top;

   stack = (struct Node**) malloc(returnListLength() * sizeof(struct Node*));
   top = -1;

   while (temp != NULL) {
      top++;

      stack[top] = temp;
      temp = temp->next;
   }

   start = stack[top];
   temp = start;

   top--;

   while (top >= 0) {
      temp->next = stack[top];
      temp = temp->next;

      top--;
   }

   temp->next = NULL;
}

int main(void) {
   int length;
   start = NULL;

   system("cls");

   printf("Enter required list length: ");
   scanf("%d", &length);

   createList(length);

   printf("\nOriginal List: ");
   display();

   reverseList();

   printf("\nReversed List: ");
   display();

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
