#include<iostream.h>
#include<process.h>
#include<math.h>

/*************************************************************/

class circle {
	private:
		double radius;
		double area;

	public:
		circle(double);
		circle(circle & );
		~circle();
		void showData();
}; //class circle

/*************************************************************/

inline circle::circle(double inputRadius) {
	radius = inputRadius;
	area = M_PI * pow(radius, 2);
} //inline circle::circle(double inputRadius)

/*************************************************************/

inline circle::circle(circle & s) {
	area = s.area + 1;
	radius = sqrt(area / M_PI);
} //inline circle::circle(circle & s)

/*************************************************************/

inline circle::~circle() {
	cout << "Destructing object" << endl << endl;
} //inline circle::~circle

/*************************************************************/

inline void circle::showData() {
	cout << "Radius: " << radius << endl;
	cout << "Area: " << area << endl << endl;
} //inline void circle::showData()

/*************************************************************/

unsigned long int count = 0;

/*************************************************************/

int main(void) {
	unsigned int rep = 1;
	unsigned int choice;

	while (rep == 1) {
		system("cls");

		double inputRadius;

		do {
			cout << "1. Enter argument as radius" << endl;
			cout << "2. Use copy constructor to increase argument by one" << endl;
			cout << "3. Exit" << endl;
			cin >> choice;

			switch (choice) {
				case 1:
					cout << endl << "Enter radius: ";
					cin >> inputRadius;

					circle c1(inputRadius);
					c1.showData();
					break;

				case 2:
					cout << endl << "Enter radius: ";
					cin >> inputRadius;

					circle c2(inputRadius);
					c2.showData();

					cout << endl << "Copied Constructor" << endl;

					circle c3(c2);
					c3.showData();
					break;

				case 3:
					goto exitLoop;

				default:
					cout << "Wrong Choice" << endl;
					break;
			} //switch (choice)

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
		} //if (count >= 50)

	} //while (rep == 1)

	cout << "Normal END" << endl;

	system("pause");
	return 0;
} //int main(void)