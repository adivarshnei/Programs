// Write a menu driven program to implement following operations on doubly
// linked list
// insert() (beginning, middle, last)
// deletion() (beginning, middle, last)
// display()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEM_LIMIT 15

typedef int LoopVar;
typedef char BufferClear;

enum Bool { TRUE = 1, FALSE = 0 };

struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};

struct Node* start = NULL;

BufferClear temp;
enum Bool shouldRepeat;

void display() {
   struct Node* temp = start;

   if (temp == NULL) {
      printf("\nNo Elements in list\n");
   } else if (temp->next == NULL) {
      printf("\nElements start to end: ");
      printf("\n%d", temp->data);
      printf("\nElements end to start: ");
      printf("\n%d", temp->data);
      printf("\n");
   } else {
      printf("\nElements start to end: ");
      printf("\n%d", temp->data);

      while (temp->next != NULL) {
         temp = temp->next;
         printf("->%d", temp->data);
      }

      printf("\nElements end to start: ");
      printf("\n%d", temp->data);

      while (temp->prev != NULL) {
         temp = temp->prev;
         printf("->%d", temp->data);
      }

      printf("\n");
   }
}

void insertAtBeg() {
   struct Node* newNode;

   int element;

   newNode = (struct Node*) malloc(sizeof(struct Node));

   element = rand() % (ELEM_LIMIT - 1) + 1;
   newNode->data = element;
   newNode->prev = NULL;
   newNode->next = NULL;

   if (start == NULL) {
      start = newNode;
   } else {
      start->prev = newNode;
      newNode->next = start;
      start = newNode;
   }

   printf("%d inserted into list\n", element);
   display();
}

void insertAtMid() {
   int position;
   int element;
   struct Node* newNode;
   struct Node* temp;
   struct Node* temp2;
   LoopVar i;

   newNode = (struct Node*) malloc(sizeof(struct Node));
   element = rand() % (ELEM_LIMIT - 1) + 1;

   newNode->data = element;
   newNode->prev = NULL;
   newNode->next = NULL;

   printf("Insert where?: ");
   scanf("%d", &position);

   if (start == NULL) {
      printf("List not initialized, inserting at start\n");

      start = newNode;
   } else {
      temp = start;

      for (i = 1; i < position - 1; i++) {
         if (temp->next != NULL) {
            temp = temp->next;
         } else {
            printf("Not enough elements, inserting at end\n");
            temp->next = newNode;
            newNode->prev = temp;

            printf("%d inserted into list\n", element);
            display();
            return;
         }
      }

      if (position == 1) {
         if (start == NULL) {
            start = newNode;
         } else {
            start->prev = newNode;
            newNode->next = start;
            start = newNode;
         }

         printf("%d inserted into list\n", element);
         display();
         return;
      }

      temp2 = temp->next;
      temp->next = newNode;
      newNode->prev = temp;
      newNode->next = temp2;
      temp2->prev = newNode;
   }

   printf("%d inserted into list\n", element);
   display();
}

void insertAtEnd() {
   struct Node* newNode;
   struct Node* temp = start;
   int element;

   newNode = (struct Node*) malloc(sizeof(struct Node));
   element = rand() % (ELEM_LIMIT - 1) + 1;

   newNode->data = rand() % (ELEM_LIMIT - 1) + 1;
   newNode->next = NULL;
   newNode->prev = NULL;

   if (start == NULL) {
      start = newNode;
   } else {
      while (temp->next != NULL) {
         temp = temp->next;
      }

      temp->next = newNode;
      newNode->prev = temp;
   }

   printf("%d inserted into list\n", newNode->data);
   display();
}

void deleteAtBeg() {
   struct Node* temp;

   if (start == NULL) {
      printf("List not initialized, cannot delete\n");

      return;
   }

   printf("%d deleted from list\n", start->data);

   temp = start;
   start = start->next;
   start->prev = NULL;

   free(temp);

   display();
}

void deleteAtMid() {
   int position;
   struct Node* temp = start;
   struct Node* temp2;

   LoopVar i;

   printf("Delete where?: ");
   scanf("%d", &position);

   if (start == NULL) {
      printf("List not initialized, cannot delete\n");

      return;
   } else if (start->next == NULL) {
      if (position > 2) {
         printf("Not enough elements, deleting from end\n");
      }

      printf("%d deleted from list", temp->data);

      free(temp);

      start = NULL;
   } else {
      for (i = 1; i < position - 1; i++) {
         if (temp->next->next != NULL) {
            temp = temp->next;
         } else {
            printf("Not enough elements, deleting from end\n");

            printf("%d deleted from list", temp->next->data);

            free(temp->next);
            temp->next = NULL;

            display();
            return;
         }
      }

      if (position == 1) {
         printf("%d deleted from list\n", start->data);

         temp = start;
         start = start->next;
         start->prev = NULL;

         free(temp);

         display();

         return;
      }

      printf("%d deleted from list\n", temp->next->data);

      temp2 = temp->next;
      temp->next = temp->next->next;
      if (temp->next != NULL) {
         temp->next->prev = temp;
      }

      free(temp2);
   }

   display();
}

void deleteAtEnd() {
   struct Node* temp = start;

   if (start == NULL) {
      printf("List not initialized. Cannot delete\n");

      return;
   } else if (start->next == NULL) {
      printf("%d deleted from list\n", start->data);

      free(start);
      start = NULL;

      display();
      return;
   }

   while (temp->next != NULL) {
      temp = temp->next;
   }

   printf("%d deleted from list\n", temp->data);

   temp->prev->next = NULL;

   free(temp);

   display();
}

void insertion() {
   int choice;

   do {
      printf("\n1. Insert at the beginning\n");
      printf("2. Insert in the middle\n");
      printf("3. Insert at the end\n");
      printf("4. Back to Main Menu\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         insertAtBeg();
         break;

      case 2:
         insertAtMid();
         break;

      case 3:
         insertAtEnd();
         break;

      case 4:
         break;

      default:
         printf("Wrong Choice\n");
         break;
      }
   } while (choice != 4);
}

void deletion() {
   int choice;

   do {
      printf("\n1. Delete at the beginning\n");
      printf("2. Delete in the middle\n");
      printf("3. Delete at the end\n");
      printf("4. Back to Main Menu\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         deleteAtBeg();
         break;

      case 2:
         deleteAtMid();
         break;

      case 3:
         deleteAtEnd();
         break;

      case 4:
         break;

      default:
         printf("Wrong Choice\n");
         break;
      }
   } while (choice != 4);
}

int main(void) {
   int choice;

   system("cls");
   srand(time(NULL));

   do {
      printf("\n1. Insertion\n");
      printf("2. Deletion\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         insertion();
         break;

      case 2:
         deletion();

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
