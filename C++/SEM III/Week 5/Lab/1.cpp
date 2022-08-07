// Take time of two zones: Current time of New Delhi, Current time of London.
// Calculate the time difference between the two cities. Use the concept of
// passing objects as parameters

#include <iostream.h>
#include <stdlib.h>
#include <math.h>

enum Bool {
   TRUE = 1,
   FALSE = 2
};

typedef char String;

// Structures

class Time {
private:
   int hours;
   int minutes;
   int seconds;
   String city[10];

public:
   Time();
   Time(int, int, int);
   ~Time();
   void correction();
};

Time::Time() {
   cout << "Time initialized to be 00:00:00" << endl;
   hours = 0;
   minutes = 0;
   seconds = 0;
}

Time::Time(int h, int m, int s) {
   hours = abs(h);
   minutes = abs(m);
   seconds = abs(s);

   correction();
}

Time::~Time() {
   cout << "Destructing Object" << endl;
}

void Time::correction() {
   Bool isCorrect = TRUE;

   while (seconds >= 60) {
      minutes++;
      seconds -= 60;

      isCorrect = FALSE;
   }

   while (minutes >= 60) {
      hours++;
      minutes -= 60;

      isCorrect = FALSE;
   }

   while (hours >= 24) {
      hours %= 24;

      isCorrect = FALSE;
   }

   if (isCorrect == FALSE) {
      cout << "Time corrected to " << hours << ":" << minutes << ":" <<
         seconds << endl;
   }
}

// Function Declarations

// Inline Functions

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Time t1;
      Time t2(10, 20, 30);
      Time t3(10, 20, 70);
      Time t4(10, 70, 70);
      Time t5(26, 70, 70);

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

// Function Definitions
