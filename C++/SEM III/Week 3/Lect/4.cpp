// Create a class Employee with appropriate data members and functions. The
// class should also have a data member document_verified and function
// verification. This function should initialize the value of verification to
// “completed and genuine”. Create appropriate objectsand call the functions.
// Make use of publicand private access specifier wherever required.

#include <iostream>
#include <stdlib.h>
#include <string.h>

// using namespace std;

typedef char String;

class Employee {
private:
   String name[50];
   int age;
   String position[50];
   long int salary;
   String* document_verified;

public:
   Employee() {
      verification();
      getData();
   }

   Employee(const String name_[50], const int age_, const String position_[50],
            const long int salary_) {
      strcpy(name, name_);
      age = age_;
      strcpy(position, position_);
      salary = salary_;

      verification();
   }
   /
      void getData() {
      std::cout << "Enter employee name: ";
      std::cin.getline(name, 50);
      std::cout << "Enter age: ";
      std::cin >> age;
      getchar();
      std::cout << "Enter position: ";
      std::cin.getline(position, 50);
      std::cout << "Enter salary: ";
      std::cin >> salary;
      getchar();
   }

   void showData() {
      std::cout << "Employee name: " << name << std::endl;
      std::cout << "Employee age: " << age << std::endl;
      std::cout << "Employee position: " << position << std::endl;
      std::cout << "Employee salary: " << salary << std::endl;
      std::cout << "Employee document status: " << document_verified << std::endl;
   }

   void verification() {
      document_verified = new String[50];
      strcpy(document_verified, "Completed and Genuine");
   }
};

int shouldRepeat;

int main(void) {
   // system("cls");

   while (1) {
      Employee e1;
      Employee e2 = Employee("B", 20, "Employee1", 5000);
      Employee e3("C", 21, "Employee3", 6000);

      e1.showData();
      e2.showData();
      e3.showData();

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
