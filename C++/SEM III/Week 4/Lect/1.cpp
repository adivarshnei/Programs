#include <iostream>

using namespace std;

class A {
private:
  int a;
  static int z;

public:
  A() {
    z++;
    cin >> a;
    cout << "Calling Constructor" << endl;
  }

  ~A() { cout << z << "Calling Destructor" << endl; }
};

int A::z = 0;

int main(void) {
  A a1, a2, a3;
  cout << A::z;

  system("pause");
  return 0;
}
