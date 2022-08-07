#include <iostream>
#include <stdio.h>

class BankAccount {
private:
   long int customerID;
   char customerName[100];
   char accountNumber[100];
   float balance;

public:
   void deposit() { }

   void withdraw() { }

   void input() {
      std::cin >> customerID >> customerName >> accountNumber >> balance;
   }

   void display() {
      std::cout << "ID: " << customerID << std::endl;
      std::cout << "Name: ";
      puts(customerName);
      std::cout << "Acc No: ";
      puts(accountNumber);
      std::cout << "Balance: " << balance << std::endl;
   }
};

int main(void) {
   BankAccount c1, c2, c3;

   c1.input();
   c2.input();
   c3.input();

   std::cout << "C1: " << std::endl;
   c1.display();

   std::cout << "C2: " << std::endl;
   c2.display();

   std::cout << "C3: " << std::endl;
   c3.display();

   return 0;
}
