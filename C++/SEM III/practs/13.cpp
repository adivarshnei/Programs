// Write a program to demonstrate simple inheritance

#include <iostream>
#include <stdlib.h>

using namespace std;

class Base {
public:
   inline void basePrint() const {
      cout << "Base Class" << endl;
   }
};

class PublicDerived : public Base {
public:
   inline void publicPrint() const {
      cout << "Publically Derived Class" << endl;
   }

   friend void publicFriend(PublicDerived);
};

class ProtectedDerived : protected Base {
public:
   inline void protectedPrint() const {
      cout << "Protectedy Derived Class" << endl;
   }

   friend void protectedFriend(ProtectedDerived);
};

class PrivateDerived : private Base {
public:
   inline void privatePrint() const {
      cout << "Publically Derived Class" << endl;
   }

   friend void privateFriend(PrivateDerived);
};

void publicFriend(PublicDerived pd) {
   cout << "Public Friend Function" << endl;
   pd.basePrint();
}

void protectedFriend(ProtectedDerived pd) {
   cout << "Protected Friend Function" << endl;
   pd.basePrint();
}

void privateFriend(PrivateDerived pd) {
   cout << "Private Friend Function" << endl;
   pd.basePrint();
}

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Base bas;
      PublicDerived pub;
      ProtectedDerived pro;
      PrivateDerived pri;

      bas.basePrint();
      cout << endl;

      pub.publicPrint();
      pub.basePrint();
      publicFriend(pub);
      cout << endl;

      pro.protectedPrint();
      // pro.basePrint();   // Throws error due to basePrint() being protected
      protectedFriend(pro);
      cout << endl;

      pri.privatePrint();
      // pri.basePrint();   // Throws error due to basePrint() being private
      privateFriend(pri);
      cout << endl;

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