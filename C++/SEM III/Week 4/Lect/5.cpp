#include <iostream>

using namespace std;

class Time {
private:
  int hours;
  int minutes;

public:
  void input() {
    cin >> hours >> minutes;

    while (1) {
      if (minutes >= 60) {
        hours++;
        minutes -= 60;
      } else {
        break;
      }
    }
  }

  void display() { cout << hours << ":" << minutes << endl; }

  void sum(Time t1, Time t2) {
    minutes = t1.minutes + t2.minutes;
    hours = minutes / 60;
    minutes = minutes % 60;
    hours = hours + t1.hours + t2.hours;
  }
};

int main(void) {
  Time t1, t2, t3;
  t1.input();
  t2.input();
  t3.sum(t1, t2);
  t3.display();

  return 0;
}
