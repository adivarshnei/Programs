// Write a program to demonstrate private simple inheritance

#include <iostream>
#include <stdlib.h>

using namespace std;

class Base {
public:
   inline void basePrint() const {
      cout << "Base Class" << endl;
   }
};

class PrivateDerived : private Base {
public:
   inline void privatePrint() const {
      cout << "Privately Defined Class" << endl;
   }

   friend void privateFriend(PrivateDerived);
};

void privateFriend(PrivateDerived pd) {
   cout << "Private Friend Function" << endl;
   pd.basePrint();
}

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Base bas;
      PrivateDerived pri;

      bas.basePrint();
      cout << endl;

      pri.privatePrint();
      // pri.basePrint();   // Throws error due to basePrint() being private
      privateFriend(pri);

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
