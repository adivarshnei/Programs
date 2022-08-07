// C++ program to demonstrate example of multilevel inheritance

#include <iostream>
#include <stdlib.h>

using namespace std;

class Base {
private:
   int baseData;

public:
   Base() {
      cout << "Within Base Class" << endl;
   }

   Base(int input) : baseData(input) {
      cout << "baseData = " << baseData << endl;
   }
};

class Intermediate : public Base {
private:
   int intermediateData;

public:
   Intermediate() : Base() {
      cout << "Within Intermediate Class" << endl;
   }

   Intermediate(int input) : Base(input * 2), intermediateData(input) {
      cout << "intermediateData = " << intermediateData << endl;
   }
};

class Derived : public Intermediate {
private:
   int derivedData;

public:
   Derived() : Intermediate() {
      cout << "Within Derived Class" << endl;
   }

   Derived(int input) : Intermediate(input * 2), derivedData(input) {
      cout << "derivedData = " << derivedData << endl;
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Derived d1;

      cout << endl;

      Derived d2(50);

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;

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
