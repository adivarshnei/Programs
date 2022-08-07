#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEM_LIMIT 10

struct Node { // Structure for a doubly linked node
   int data;
   struct Node* next;
   struct Node* prev;
};

struct Node* start = NULL; // List always starts out as empty

void display() {
   struct Node* temp = start;

   if (temp == NULL) { // If List is Empty
      printf("\nNo Elements in List\n");
   } else if (temp->next == NULL) { // If List has only one element
      printf("\nElements start to end: ");
      printf("\n%d", temp->data);
      printf("\nElements end to start: ");
      printf("\n%d", temp->data);
      printf("\n");
   } else { // All other cases
      printf("\nElements start to end: ");
      printf("\n%d", temp->data);
      
      while (temp->next != NULL) { // Iterates over list going to next element
         temp = temp->next;
         printf("->%d", temp->data);
      }
      
      printf("\nElements end to start: ");
      printf("\n%d", temp->data);
      
      while (temp->prev != NULL) { // Iterates over list going to previous element
         temp = temp->prev;
         printf("->%d", temp->data);
      }
      
      printf("\n");
   }
}

void insertAtBeg() {
   struct Node* newNode;

   int element = (rand() % ELEM_LIMIT) + 1; // Gets random value for element between (1, 10)
   
   newNode = (struct Node*) malloc(sizeof(struct Node)); // Allocation of new node
   newNode->data = element; // Data given to new node
   newNode->next = NULL; // Initially, newNode links to no element
   newNode->prev = NULL;

   if (start == NULL) { // If List is empty
      start = newNode; // New node is only element if list was previously empty
   } else { // All other cases
      start->prev = newNode; // New node is start's previous element
      newNode->next = start; // Start is new node's next element
      start = newNode; // New node is at the beginning of the list, and is therefore now the start
   }
}

int main(void){
   int choice;
   
   // system("cls"); // GCC Windows only
   
   // Creates new seed for rand()
   srand(time(NULL));
   
   // Menu driven program
   do {
      printf("1. Insert Element\n");
      printf("2. Display\n");
      printf("3. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);
      
      switch(choice) {
      case 1: // Insertion at beginning of list
         insertAtBeg();
         display();
         break;
         
      case 2: // Display List Front and Back 
         display();
         break;
         
      case 3: // Exits Program
         break;
         
      default: // Wrong Choice Entered
         printf("Wrong Choice.\n");
         break;
      }
   } while(choice != 3);
   
   return 0;
}
