#include<iostream.h>
#include<process.h>

/*************************************************************/

class time {
	private:
		unsigned int hours;
		unsigned int minutes;
		unsigned int seconds;

	public:
		time();
		time(int, int, int);
		~time();
		unsigned int returnHours();
		unsigned int returnMinutes();
		unsigned int returnSeconds();
		void displayTime();
		void addTime(time, time);
};//class time

/*************************************************************/

inline time::time() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}//inline time::time()

/*************************************************************/

inline time::time(int inputHours, int inputMinutes, int inputSeconds) {
	hours = inputHours;
	minutes = inputMinutes;
	seconds = inputSeconds;
}//inline time::time(int inputHours, int inputMinutes, int inputSeconds)

/*************************************************************/

inline time::~time(){
	cout<<endl<<"Destructing Object"<<endl;
}

/*************************************************************/

inline unsigned int time::returnHours() {
	return hours;
}//inline unsigned int time::returnHours()

/*************************************************************/

inline unsigned int time::returnMinutes() {
	return minutes;
}//inline unsigned int time::returnMinutes()

/*************************************************************/

inline unsigned int time::returnSeconds() {
	return seconds;
}//inline unsigned int time::returnSeconds()

/*************************************************************/

void time::displayTime() {
	do {

		if (seconds >= 60) {
			seconds -= 60;
			minutes++;
			continue;
		} else if (seconds < 60) {
			break;
		}//End of extended if clause
	
	} while (1);

	do {

		if (minutes >= 60) {
			minutes -= 60;
			hours++;
			continue;
		} else if (minutes < 60) {
			break;
		}//End of extended if clause

	} while (1);

	cout << "Time is" << endl;
	cout << hours << ":" << minutes << ":" << seconds << endl;
}//void time::displayTime() 

inline void time::addTime(time t1, time t2) {
	hours = t1.returnHours() + t2.returnHours();
	minutes = t1.returnMinutes() + t2.returnMinutes();
	seconds = t1.returnSeconds() + t2.returnSeconds();

	displayTime();
}//inline void time::addTime(time t1, time t2)

/*************************************************************/

unsigned long count = 0;

/*************************************************************/

int main(void) {
	unsigned int rep = 1;
	unsigned int choice1, choice2;

	while (rep == 1) {
		system("cls");

		unsigned int inputHours, inputMinutes, inputSeconds;

		do {
			cout << "1. Input time and display" << endl;
			cout << "2. Add two times" << endl;
			cout << "3. Exit" << endl;
			cin >> choice1;

			switch (choice1) {
				case 1:
					cout << "1. Use default constructor" << endl;
					cout << "2. Use parameterized constructor" << endl;
					cout << "3. Exit" << endl;
					cin >> choice2;
					
					if (choice2 == 1) {
						time t1;
						t1.displayTime();
					} else if (choice2 == 2) {
						cout << "Enter time t:" << endl;
						cout << "Hours: ";
						cin >> inputHours;
						cout << "Minutes: ";
						cin >> inputMinutes;
						cout << "Seconds: ";
						cin >> inputSeconds;

						time t2(inputHours, inputMinutes, inputSeconds);
						t2.displayTime();
					} else if (choice2 == 3) {
						goto exitLoop;
					}//End of extended if clause

					break;

				case 2:
					cout << "1. Use default constructor" << endl;
					cout << "2. Use parameterized constructor" << endl;
					cout << "3. Exit" << endl;
					cin >> choice2;

					if (choice2 == 1) {
						inputHours = 0;
						inputMinutes = 0;
						inputSeconds = 0;
					} else if (choice2 == 2) {
						cout << "Enter time t1:" << endl;
						cout << "Hours: ";
						cin >> inputHours;
						cout << "Minutes: ";
						cin >> inputMinutes;
						cout << "Seconds: ";
						cin >> inputSeconds;
					} else if (choice2 == 3) {
						goto exitLoop;
					}//End of extended if clause

					time t3(inputHours, inputMinutes, inputSeconds);

					cout << "1. Use default constructor" << endl;
					cout << "2. Use parameterized constructor" << endl;
					cout << "3. Exit" << endl;
					cin >> choice2;

					if (choice2 == 1) {
						inputHours = 0;
						inputMinutes = 0;
						inputSeconds = 0;
					} else if (choice2 == 2) {
						cout << "Enter time t1:" << endl;
						cout << "Hours: ";
						cin >> inputHours;
						cout << "Minutes: ";
						cin >> inputMinutes;
						cout << "Seconds: ";
						cin >> inputSeconds;
					} else if (choice2 == 3) {
						goto exitLoop;
					}//End of extended if clause

					time t4(inputHours, inputMinutes, inputSeconds);
					time t5;

					t5.addTime(t3, t4);
					break;

				case 3:
					goto exitLoop;
					break;

				default:
					cout<<"Wrong Choice"<<endl;
					break;
			}//switch (choice1)

		} while (1);

		exitLoop:
		cout << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			system("cls");

			cout << "Abnormal END" << endl;

			system("pause");
			exit(0);
		}//if (count >= 50)

	}//while (rep == 1)

	cout << "Normal END" << endl;

	system("pause");
	return 0;
}//int main(void)