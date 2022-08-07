#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define ELEM_LIMIT 10
#define OUT_OF_BOUNDS -1

using namespace std;

int shouldRepeat;

void initArray(int* array) {
   for (int i = 0; i < ARRAY_SIZE; i++) {
      array[i] = rand() % (ELEM_LIMIT - 1) + 1;
   }
}

void printArray(int* array) {
   cout << "Array: ";

   for (int i = 0; i < ARRAY_SIZE; i++) {
      cout << array[i] << " ";
   }

   cout << endl;
}

int seek(int* array, int index) {
   if (index >= ARRAY_SIZE) {
      throw OUT_OF_BOUNDS;
   }

   return array[index];
}

int main(void) {
   system("cls");

   while (1) {
      int array[ARRAY_SIZE];
      int seekIndex;
      int element;

      srand(time(NULL));

      initArray(array);
      printArray(array);

      cout << "Find element at which index: ";
      cin >> seekIndex;

      try {
         element = seek(array, seekIndex);
      } catch (int errCode) {
         if (errCode = ARRAY_SIZE) {
            cerr << "Array index out of bounds error" << endl;
            goto END;
         }
      }

      cout << "array[" << seekIndex << "] = " << element << endl;

   END:
      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;
      cin.ignore(256, '\n');

      if (shouldRepeat == 1) {
         continue;
      } else {
         cout << endl << "END" << endl;
         break;
      }
   }

   system("pause");
   return 0;
}
