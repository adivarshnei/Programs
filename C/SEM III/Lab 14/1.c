// Write a program to implement creation, insertion & display of Binary Search
// Trees

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

struct Node* root = NULL;
int n = 0;

BufferClear temp;
enum Bool shouldRepeat;

void insertRecursion(struct Node* newNode, struct Node* temp) {
   if (newNode->data < temp->data) {
      if (temp->left == NULL) {
         temp->left = newNode;
         return;
      }

      insertRecursion(newNode, temp->left);
   } else if (newNode->data > temp->data) {
      if (temp->right == NULL) {
         temp->right = newNode;
         return;
      }

      insertRecursion(newNode, temp->right);
   }
}

void insertion(int entryStyle, struct Node* temp, int n) {
   struct Node* newNode;
   int element;

   newNode = (struct Node*) malloc(sizeof(struct Node));

   element = (entryStyle == RANDOM) ? (rand() % (ELEM_LIMIT - 1) + n) : n;

   newNode->data = element;
   newNode->left = NULL;
   newNode->right = NULL;

   if (root == NULL) {
      root = newNode;
      return;
   }

   if (newNode->data == temp->data) {
      if (entryStyle == RANDOM) {
         insertion(entryStyle, root, n + 1);
      } else {
         insertion(entryStyle, root, n);
      }
   } else {
      insertRecursion(newNode, temp);
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

   root = NULL;
   n = 0;

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
         insertion(entryStyle, root, n++);
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
