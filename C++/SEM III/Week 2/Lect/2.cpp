// #include <iostream>
// #include <stdio.h>

// using namespace std;

// class BankAccount {
// private:
//    long int customerID;
//    char customerName[100];
//    char accountNumber[100];
//    float balance;

// public:
//    void deposit() { }
//    void withdraw() { }
//    void input() {
//       cin >> customerID >> customerName >> accountNumber >> balance;
//    }
//    void display() {
//       cout << "ID: " << customerID << endl;
//       cout << "Name: ";
//       puts(customerName);
//       cout << "Acc No.: ";
//       puts(accountNumber);
//       cout << "Balance: " << balance << endl;
//    }
// };

// int main(void) {
//    BankAccount c1, c2, c3;

//    c1.input();
//    c2.input();
//    c3.input();

//    cout << "C1: " << endl;
//    c1.display();

//    cout << endl << "C2: " << endl;
//    c2.display();

//    cout << endl << "C3: " << endl;
//    c3.display();
// }

class Customer {
private:
   long int customerID;
   char name[20];
   int age;
   char gender[5];

public:
   void getData();
   void showData();
};

Customer c1, c2, c3, c4;
