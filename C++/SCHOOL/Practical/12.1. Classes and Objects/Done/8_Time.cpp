#include<iostream.h>
#include<process.h>

class Time {
	private:
		long int hours;
		long int minutes;
		long int seconds;

	public:
		void readTime(long int, long int, long int);
		void showTime();
		void addTime(Time, Time);
		long int returnHours();
		long int returnMinutes();
		long int returnSeconds();
};

inline long int Time::returnHours() {
	return hours;
}

inline long int Time::returnMinutes() {
	return minutes;
}

inline long int Time::returnSeconds() {
	return seconds;
}

void Time::readTime(long int h, long int m, long int s) {
	hours = h;
	minutes = m;
	seconds = s;

	do {
		if (seconds >= 60) {
			seconds -= 60;
			minutes++;
			continue;
		} else if (seconds < 60) {
			break;
		}
	} while (1);

	do {
		if (minutes >= 60) {
			minutes -= 60;
			hours++;
			continue;
		} else if (minutes < 60) {
			break;
		}
	} while (1);

}

inline void Time::showTime() {
	cout << "Time is " << endl;
	cout << hours << ":" << minutes << ":" << seconds << endl;
}

void Time::addTime(Time t1, Time t2) {
	hours = t1.returnHours() + t2.returnHours();
	minutes = t1.returnMinutes() + t2.returnMinutes();
	seconds = t1.returnSeconds() + t2.returnSeconds();

	do {
		if (seconds >= 60) {
			seconds -= 60;
			minutes++;
			continue;
		} else if (seconds < 60) {
			break;
		}
	} while (1);

	do {
		if (minutes >= 60) {
			minutes -= 60;
			hours++;
			continue;
		} else if (minutes < 60) {
			break;
		}
	} while (1);

}

long count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		system("cls");

		Time t1, t2, t3;
		long int h, m, s;
		int choice;

		choiceLocation:
		cout << "1. Add two times" << endl;
		cout << "2. Initialize a time object" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter time t1:" << endl;
				cout << "Hours: ";
				cin >> h;
				cout << "Minutes: ";
				cin >> m;
				cout << "Seconds: ";
				cin >> s;
				t1.readTime(h, m, s);

				cout << "Enter time t2:" << endl;
				cout << "Hours: ";
				cin >> h;
				cout << "Minutes: ";
				cin >> m;
				cout << "Seconds: ";
				cin >> s;
				t2.readTime(h, m, s);

				t3.addTime(t1, t2);
				cout << "t3: " << endl;
				t3.showTime();
				goto choiceLocation;

			case 2:
				cout << "Enter time t:" << endl;
				cout << "Hours: ";
				cin >> h;
				cout << "Minutes: ";
				cin >> m;
				cout << "Seconds: ";
				cin >> s;
				t1.readTime(h, m, s);
				t1.showTime();
				goto choiceLocation;

			case 3:
				break;

			default:
				cout << "Wrong Choice" << endl;
				goto choiceLocation;
				break;
		}

		cout << endl << endl << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			system("cls");

			cout << "Abnormal END" << endl;

			system("pause");
			exit(0);
		}

	}

	cout << "Normal END" << endl;

	system("pause");
	return 0;
}