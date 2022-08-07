// Write a program to implement creation, insertion and display of Binary Trees

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEM_LIMIT 10

#define NUMERICAL 1
#define RANDOM 2

typedef int LoopVar;
typedef char BufferClear;

enum Bool { TRUE = 1, FALSE = 0 };

struct Node {
   int data;
   struct Node* left;
   struct Node* right;
};

struct queueNode {
   struct Node* node;
   struct queueNode* next;
};

struct Node* root = NULL;
struct queueNode* front = NULL;
struct queueNode* rear = NULL;
int n = 0;

BufferClear temp;
enum Bool shouldRepeat;

void enqueue(struct Node* node) {
   struct queueNode* newNode;

   newNode = (struct queueNode*) malloc(sizeof(struct queueNode));
   newNode->node = node;
   newNode->next = NULL;

   if (front == NULL) {
      front = newNode;
      rear = newNode;
   } else {
      rear->next = newNode;
      rear = newNode;
   }
}

void dequeue() {
   struct queueNode* temp;

   if (front == NULL) {
      return;
   }

   temp = front;
   front = front->next;

   if (front == NULL) {
      rear = NULL;
   }

   free(temp);
}

void emptyQueue() {
   while (front != NULL) {
      dequeue();
   }
}

void insertion(int entryStyle) {
   struct Node* newNode;
   struct Node* temp;
   int element;

   newNode = (struct Node*) malloc(sizeof(struct Node));

   element = (entryStyle == RANDOM) ? (rand() % (ELEM_LIMIT - 1) + 1) : n++;

   newNode->data = element;
   newNode->left = NULL;
   newNode->right = NULL;

   if (root == NULL) {
      root = newNode;
      return;
   }

   emptyQueue();
   enqueue(root);

   while (front != NULL) {
      temp = front->node;
      dequeue();

      if (temp->left != NULL) {
         enqueue(temp->left);
      } else {
         temp->left = newNode;
         return;
      }

      if (temp->right != NULL) {
         enqueue(temp->right);
      } else {
         temp->right = newNode;
         return;
      }
   }
}

void inorder(struct Node* node) {
   if (node == NULL) {
      return;
   }

   inorder(node->left);
   printf("%d ", node->data);
   inorder(node->right);
}

void postorder(struct Node* node) {
   if (node == NULL) {
      return;
   }

   postorder(node->left);
   postorder(node->right);
   printf("%d ", node->data);
}

void preorder(struct Node* node) {
   if (node == NULL) {
      return;
   }

   printf("%d ", node->data);
   preorder(node->left);
   preorder(node->right);
}

void display() {
   printf("\nInorder Traversal: ");
   inorder(root);

   printf("\nPostorder Traversal: ");
   postorder(root);

   printf("\nPreorder Traversal: ");
   preorder(root);

   printf("\n");
}

int main(void) {
   int choice;
   int entryStyle;

   system("cls");
   srand(time(NULL));

   do {
      printf("1. Enter numbers in numerical order (i.e. 1, 2, 3, 4...)\n");
      printf("2. Enter random numbers\n");
      scanf("%d", &entryStyle);
   } while (entryStyle != NUMERICAL && entryStyle != RANDOM);

   do {
      printf("\n1. Insertion\n");
      printf("2. Display\n");
      printf("3. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         insertion(entryStyle);
         display();
         break;

      case 2:
         display();
         break;

      case 3:
         break;

      default:
         printf("Wrong Choice\n");
         break;
      }
   } while (choice != 3);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
