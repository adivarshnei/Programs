// Write a program to implement deletion & display of Binary Search Trees

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEM_LIMIT 100
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

void swap(int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void shuffle(int* array, int size) {
   LoopVar i, j;
   int t;

   for (i = 0; i < size; i++) {
      j = rand() % size;
      swap(&array[i], &array[j]);
   }
}

void generate(int* array, int size, int entryStyle) {
   LoopVar i, j;
   int element;
   int index = 0;
   enum Bool isValid;

   while (index < size) {
      isValid = TRUE;
      element = (entryStyle == RANDOM) ? (rand() % (ELEM_LIMIT + size + n)) : n;

      for (i = 0; i < index; i++) {
         if (element == array[i]) {
            printf("1");
            isValid = FALSE;
            n++;
            break;
         }
      }

      if (isValid == TRUE) {
         array[index] = element;
         index++;
      }

      printf("%d, %d\n", index, n);
   }

   if (entryStyle == RANDOM) {
      shuffle(array, size);
   }
}

// void insertRecursion(struct Node* newNode, struct Node* temp) {
//    if (newNode->data < temp->data) {
//       if (temp->left == NULL) {
//          temp->left = newNode;
//          printf("%d\n", newNode->data);
//          return;
//       }

//       insertRecursion(newNode, temp->left);
//    } else if (newNode->data > temp->data) {
//       if (temp->right == NULL) {
//          temp->right = newNode;
//          printf("%d\n", newNode->data);
//          return;
//       }

//       insertRecursion(newNode, temp->right);
//    }
// }

// void insertion(int element, struct Node* temp, int n, int size) {
//    struct Node* newNode;
//    int element;

//    newNode = (struct Node*) malloc(sizeof(struct Node));

//    newNode->data = element;
//    newNode->left = NULL;
//    newNode->right = NULL;

//    if (root == NULL) {
//       newNode->data += size / 2;
//       root = newNode;
//       printf("%d\n", newNode->data);
//       return;
//    }

//    if (newNode->data == temp->data) {
//       if (entryStyle == RANDOM) {
//          insertion(entryStyle, root, n + 1, size);
//       } else {
//          insertion(entryStyle, root, n, size);
//       }
//    } else {
//       insertRecursion(newNode, temp);
//    }
// }

// struct Node* minNode(struct Node* node) {
//    struct Node* current = node;

//    while (current != NULL && current->left != NULL) {
//       current = current->left;
//    }

//    return current;
// }

// struct Node* deleteRecursion(struct Node* node, int key) {
//    struct Node* temp;

//    if (node == NULL) {
//       printf("Element not found.\n");
//       return node;
//    }

//    if (node->data > key) {
//       node->left = deleteRecursion(node->left, key);
//    } else if (node->data < key) {
//       node->right = deleteRecursion(node->right, key);
//    } else {
//       if (node->left == NULL) {
//          temp = node->right;
//          free(node);
//          return temp;
//       } else if (node->right == NULL) {
//          temp = node->left;
//          free(node);
//          return temp;
//       }

//       temp = minNode(node->right);
//       node->data = temp->data;
//       node->right = deleteRecursion(node->right, temp->data);
//    }

//    return node;
// }

// void deletion() {
//    int key;

//    if (root == NULL) {
//       printf("Cannot delete from empty list.\n");
//       return;
//    }

//    printf("Delete which element?: ");
//    scanf("%d", &key);

//    root = deleteRecursion(root, key);
// }

// void inorder(struct Node* node) {
//    if (node == NULL) {
//       return;
//    }

//    inorder(node->left);
//    printf("%d ", node->data);
//    inorder(node->right);
// }

// void postorder(struct Node* node) {
//    if (node == NULL) {
//       return;
//    }

//    postorder(node->left);
//    postorder(node->right);
//    printf("%d ", node->data);
// }

// void preorder(struct Node* node) {
//    if (node == NULL) {
//       return;
//    }

//    printf("%d ", node->data);
//    preorder(node->left);
//    preorder(node->right);
// }

// void display() {
//    printf("\nInorder Traversal: ");
//    inorder(root);

//    printf("\nPostorder Traversal: ");
//    postorder(root);

//    printf("\nPreorder Traversal: ");
//    preorder(root);

//    printf("\n");
// }

int main(void) {
   int choice;
   int entryStyle;
   int noOfNodes;
   LoopVar i;
   int* elementArray;

   system("cls");
   srand(time(NULL));

   root = NULL;
   n = 0;

   do {
      printf("1. Enter numbers in numerical order (i.e. 1, 2, 3, 4...)\n");
      printf("2. Enter random numbers\n");
      scanf("%d", &entryStyle);
   } while (entryStyle != NUMERICAL && entryStyle != RANDOM);

   printf("Insert how many elements?: ");
   scanf("%d", &noOfNodes);

   elementArray = (int*) malloc(sizeof(int) * noOfNodes);

   generate(elementArray, noOfNodes, entryStyle);
   shuffle(elementArray, noOfNodes);

   for (i = 0; i < noOfNodes; i++) {
      printf("%d ", elementArray[i]);
   }

   // for (i = 0; i < noOfNodes; i++) {
   //    insertion(entryStyle, root, n++, noOfNodes);
   // }

   // display();

   // do {
   //    printf("\n1. Deletion\n");
   //    printf("2. Display\n");
   //    printf("3. Exit\n");
   //    printf("Enter Choice: ");
   //    scanf("%d", &choice);

   //    switch (choice) {
   //    case 1:
   //       deletion();
   //       display();
   //       break;

   //    case 2:
   //       display();
   //       break;

   //    case 3:
   //       break;

   //    default:
   //       printf("Wrong Choice\n");
   //       break;
   //    }
   // } while (choice != 3);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
