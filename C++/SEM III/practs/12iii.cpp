// Take time of two zones: Current time of city 1 and current time of city 2.
// Calculate the time difference between two cities. Use the concept of passing
// objects as parameters.

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef char String;

class Time {
private:
   int hours;
   int minutes;
   int seconds;

public:
   Time() : hours(0), minutes(0), seconds(0) { }

   Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
      correction();
   }

   int returnTotalSeconds() { return ((hours * 60) + minutes) * 60 + seconds; }

   int returnHours() { return hours; }

   int returnMinutes() { return minutes; }

   int returnSeconds() { return seconds; }

   void correction() {
      hours = abs(hours);
      minutes = abs(minutes);
      seconds = abs(seconds);

      while (seconds >= 60) {
         minutes++;
         seconds -= 60;
      }

      while (minutes >= 60) {
         hours++;
         minutes -= 60;
      }

      while (hours >= 24) {
         hours %= 24;
      }
   }
};

int shouldRepeat;

void timeDifference(Time t1, Time t2) {
   int ahead =
       (t1.returnTotalSeconds() > t2.returnTotalSeconds())
           ? 1
           : ((t1.returnTotalSeconds() < t2.returnTotalSeconds()) ? 2 : 0);
   Time* diff;

   if (ahead == 1) {
      diff = new Time(0, 0, t1.returnTotalSeconds() - t2.returnTotalSeconds());
   } else if (ahead == 2) {
      diff = new Time(0, 0, t2.returnTotalSeconds() - t1.returnTotalSeconds());
   }

   if (ahead == 1) {
      cout << "City 1 is ahead of City 2 by " << diff->returnHours() << ":"
           << diff->returnMinutes() << ":" << diff->returnSeconds() << endl;

      delete diff;
   } else if (ahead == 2) {
      cout << "City 2 is ahead of City 1 by " << diff->returnHours() << ":"
           << diff->returnMinutes() << ":" << diff->returnSeconds() << endl;

      delete diff;
   } else {
      cout << "Both cities are at the same time zone." << endl;
   }
}

int main(void) {
   system("cls");

   while (1) {
      int h1, m1, s1;
      int h2, m2, s2;

      cout << "Enter time of city 1: " << endl;
      cout << "Hours: ";
      cin >> h1;
      cout << "Minutes: ";
      cin >> m1;
      cout << "Seconds: ";
      cin >> s1;

      cout << "Enter time of city 1: " << endl;
      cout << "Hours: ";
      cin >> h2;
      cout << "Minutes: ";
      cin >> m2;
      cout << "Seconds: ";
      cin >> s2;

      Time t1(h1, m1, s1);
      Time t2(h2, m2, s2);

      timeDifference(t1, t2);

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
