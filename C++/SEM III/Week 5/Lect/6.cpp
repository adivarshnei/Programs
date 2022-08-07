#include <iostream>

class Alpha {
private:
   int data;

public:
   Alpha() { }
   Alpha(int d) {
      data = d;
   }
   Alpha(Alpha& a) {
      data = a.data;
      std::cout << "\nCopy Constructor invoked" << std::endl;
   }
   void display() const {
      std::cout << data << std::endl;
   }
};

int main(void) {
   Alpha a1(5);
   Alpha a2(a1);
   a1.display();
   a2.display();
}