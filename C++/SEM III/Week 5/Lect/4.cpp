#include <iostream>

using namespace std;

class beta;

class alpha {
private:
   int data;

public:
   alpha() {
      data = 3;
   }

   friend int frifunc(alpha, beta);
};

class beta {
private:
   int data;

public:
   beta() :data(7) { } // Alternate way of writing constructors
   friend int frifunc(alpha, beta);
};

int frifunc(alpha a, beta b) {
   return a.data + b.data;
}

int main(void) {
   alpha aa;
   beta bb;

   cout << frifunc(aa, bb);
}