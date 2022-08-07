// Write a program to demonstrate protected simple inheritance

#include <iostream>
#include <stdlib.h>

using namespace std;

class Base {
public:
   inline void basePrint() const {
      cout << "Base Class" << endl;
   }
};

class ProtectedDerived : protected Base {
public:
   inline void protectedPrint() const {
      cout << "Privately Defined Class" << endl;
   }

   friend void protectedFriend(ProtectedDerived);
};

void protectedFriend(ProtectedDerived pd) {
   cout << "Protected Friend Function" << endl;
   pd.basePrint();
}

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Base bas;
      ProtectedDerived pro;

      bas.basePrint();
      cout << endl;

      pro.protectedPrint();
      // pro.basePrint();   // Throws error due to basePrint() being protected
      protectedFriend(pro);

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
