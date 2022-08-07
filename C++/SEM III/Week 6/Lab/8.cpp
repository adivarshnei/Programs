// C++ program to demonstrate example of hierarchical inheritance to get
// square and cube of a number

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef char String;

class BaseNumber {
protected:
   static int number;
   static int isInit;

public:
   static void getNumber() {
      cout << "Enter a number: ";
      cin >> number;
      isInit = 1;
   }
};

int BaseNumber::number = 0;
int BaseNumber::isInit = 0;

class Square;
class Cube;

class Square : public BaseNumber {
private:
   int squareNumber;

public:
   void squareOperation() {
      if (isInit == 0) {
         getNumber();
      }

      squareNumber = number * number;
   }

   friend void performOperations(Square, Cube);
};

class Cube : public BaseNumber {
private:
   int cubeNumber;

public:
   void cubeOperation() {
      if (isInit == 0) {
         getNumber();
      }

      cubeNumber = number * number * number;
   }

   friend void performOperations(Square, Cube);
};

int shouldRepeat;

void performOperations(Square square, Cube cube) {
   square.squareOperation();
   cube.cubeOperation();

   cout << square.number << " ^ 2 = " << square.squareNumber << endl;
   cout << cube.number << " ^ 3 = " << cube.cubeNumber << endl;
}

int main(void) {
   system("cls");

   while (1) {
      Square s;
      Cube c;

      performOperations(s, c);

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
