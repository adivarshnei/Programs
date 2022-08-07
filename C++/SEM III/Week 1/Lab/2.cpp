// Program to calculate area of a circle

#include <iostream.h>
#include <stdlib.h>
#include <math.h>

enum Bool {
   YES = 1,
   NO = 0
};

enum Bool shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      float radius, area;

      cout << "Enter radius of the circle: ";
      cin >> radius;

      area = M_PI * radius * radius;

      cout << "Area = " << area << endl;

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;

      if (shouldRepeat == YES) {
         continue;
      } else {
         break;
      }
   }
}