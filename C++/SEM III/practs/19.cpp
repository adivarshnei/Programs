// Write a program to demonstrate multiple inheritance

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef char String;

class Base1 {
private:
   int base1Data;

public:
   Base1() {
      cout << "Within Base1 Class" << endl;
   }

   Base1(int input) : base1Data(input) {
      cout << "base1Data = " << base1Data << endl;
   }
};

class Base2 {
private:
   int base2Data;

public:
   Base2() {
      cout << "Within Base2 Class" << endl;
   }

   Base2(int input) : base2Data(input) {
      cout << "base2Data = " << base2Data << endl;
   }
};

class Derived : public Base1, public Base2 {
private:
   int derivedData;

public:
   Derived() : Base1(), Base2() {
      cout << "Within Derived Class" << endl;
   }

   Derived(int input) : Base1(input * 2), Base2(input * 4), derivedData(input) {
      cout << "derivedData = " << derivedData << endl;
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Derived d1;

      cout << endl;

      Derived d2(100);

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
