// Create a class Bank Account with appropriate data members and functions.
// The class should also have a data member opening_balance and function
// set_opening_balance.This function should initialize the value of
// opening_balance to 10000. Create appropriate objects and call the functions.
// Make use of public and private access specifier wherever required.

#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef char String;
typedef int LoopVar;

class BankAccount {
private:
   String holderName[20];
   String holderAddress[50];
   String accountNumber[20];
   long int customerID;
   long int opening_balance;

public:
   BankAccount() {
      opening_balance = 10000;

      getData();
   }

   BankAccount(const String holderName_[20], const String holderAddress_[50],
               const String accountNumber_[50], long int customerID_) {
      opening_balance = 10000;

      strcpy(holderName, holderName_);
      strcpy(holderAddress, holderAddress_);
      strcpy(accountNumber, accountNumber_);
      customerID = customerID_;
   }

   void getData() {
      std::cout << "Enter holder name: ";
      std::cin.getline(holderName, 20);
      std::cout << "Enter holder address: ";
      std::cin.getline(holderAddress, 50);
      std::cout << "Enter account number: ";
      std::cin.getline(accountNumber, 20);
      std::cout << "Enter customer ID: ";
      std::cin >> customerID;
      getchar();
   }

   void showData() {
      std::cout << "Account holder: ";
      puts(holderName);
      std::cout << "Address: ";
      puts(holderAddress);
      std::cout << "Account Number: ";
      puts(accountNumber);
      std::cout << "Customer ID: " << customerID << std::endl;
      std::cout << "Opening Balance: " << opening_balance << std::endl;
   }
};

int shouldRepeat;

int main(void) {
   // system("cls");

   while (1) {
      BankAccount accounts[3];
      BankAccount account("d", "w", "456", 78);

      // for (LoopVar i = 0; i < 3; i++) {
      //    std::cout << std::endl << "Account " << i + 1 << ": " << std::endl;
      //    accounts[i].getData();
      // }

      for (LoopVar i = 0; i < 3; i++) {
         std::cout << std::endl << "Account " << i + 1 << ": " << std::endl;
         accounts[i].showData();
         system("pause");
      }

      std::cout << std::endl;

      account.showData();

      std::cout << std::endl << "Repeat Program? (1 = YES): ";
      std::cin >> shouldRepeat;

      if (shouldRepeat == 1) {
         continue;
      } else {
         std::cout << std::endl << "END" << std::endl;
         break;
      }
   }

   system("pause");
   return 0;
}

// Function Definitions
