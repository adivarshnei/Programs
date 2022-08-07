#include <iostream>

using namespace std;

class Passenger {
private:
   int index;
   static int passengerCount;

public:
   Passenger() {
      index = passengerCount;
      passengerCount++;
   }

   static void showPassengerCount() {
      cout << endl << "No of Passengers: " << passengerCount << endl;
   }
};

void addPassenger();

int Passenger::passengerCount = 0;

int main(void) {
   Passenger p;
   int choice;

   do {
      cout << "1. Add passenger" << endl;
      cout << "2. Show no of passengers" << endl;
      cout << "3. Exit" << endl;
      cin >> choice;

      switch (choice) {
      case 1:
         addPassenger();

      case 2:
         Passenger::showPassengerCount();
         break;

      case 3:
         break;

      default:
         cout << "Wrong Choice" << endl;
         break;
      }
   } while (choice != 3);

   return 0;
}

void addPassenger() {
   Passenger p1;
}
