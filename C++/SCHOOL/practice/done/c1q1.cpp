#include<iostream.h>
#include<process.h>
#include<math.h>

typedef struct coordinate {
	double x;
	double y;
};

coordinate inputCoordinates();

double findDist(coordinate, coordinate);

unsigned long int count = 0;

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		coordinate c1, c2;

		cout << "First coordinate entry: " << endl;
		c1 = inputCoordinates();

		cout << endl << "Second coordinate entry: " << endl;
		c2 = inputCoordinates();

		cout << endl << "Distance between the coordinates is: " << findDist(c1, c2) << endl << endl;

		cout << "Repeat Program?" << endl;
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

coordinate inputCoordinates() {
	coordinate c;

	cout << "Enter the abscissa: ";
	cin >> c.x;
	cout << "Enter the ordinate: ";
	cin >> c.y;

	return c;
}

double findDist(coordinate c1, coordinate c2) {
	double dist = sqrt(((c1.x - c2.x) * (c1.x - c2.x)) + ((c1.y - c2.y) * (c1.y - c2.y)));

	return dist;
}