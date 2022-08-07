#include<iostream.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

//*************************************************************************

typedef char string;

//*************************************************************************

class floppyBox {
	private:
		int floppyNo;
		int size;
		string name[20];

	public:
		void getData();
		void showData();
		void findSize();
		void searchFloppy(int);
		int searchName(string[]);
		int returnSize();
};

//*************************************************************************

inline void floppyBox::getData() {
	cout << "Enter floppy number: ";
	cin >> floppyNo;
	cout << "Enter floppy name: ";
	gets(name);
	findSize();
}

//*************************************************************************

inline void floppyBox::showData() {
	cout << "Floppy Number: " << floppyNo << endl;
	cout << "Floppy Size: " << size << endl;
	cout << "Floppy Name: ";
	puts(name);
}

//*************************************************************************

inline void floppyBox::findSize() {
	int foundSize = strlen(name);
	size = foundSize;
}

//*************************************************************************

inline void floppyBox::searchFloppy(int inputFloppyNo) {
	if (inputFloppyNo == floppyNo) {
		cout << "Floppy Found: " << endl;
		showData();
	} else {
		cout << "Floppy not found" << endl;
	}
}

//*************************************************************************

inline int floppyBox::searchName(string inputFloppyName[]) {
	if (strcmp(inputFloppyName, name) == 0) {
		return 1;
	} else {
		return 0;
	}
}

//*************************************************************************

inline int floppyBox::returnSize() {
	return size;
}

//*************************************************************************

long count = 0;

//*************************************************************************

int main(void) {
	int rep = 1;

	while (rep == 1) {
		system("cls");

		floppyBox f[4];
		int choice, i;
		int inputFloppyNo;
		string inputFloppyName[20];

		cout << "Enter floppy data: " << endl;
		
		for (i = 0; i < 4; i++) {
			f[i].getData();
		}

		choiceLocation:
		cout << endl << "1. Search by floppy number" << endl;
		cout << "2. Sort floppies by size" << endl;
		cout << "3. Count by floppy name" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter floppy number: ";
				cin >> inputFloppyNo;

				for (i = 0; i < 4; i++) {
					f[i].searchFloppy(inputFloppyNo);
				}

				goto choiceLocation;

			case 2:
				floppyBox temp;

				for (i = 0; i < 4; i++) {

					for (int j = i + 1; j < 4; j++) {

						if (f[i].returnSize() < f[j].returnSize()) {
							temp = f[i];
							f[i] = f[j];
							f[j] = temp;
						}

					}

				}

				for (i = 0; i < 4; i++) {
					f[i].showData();
					system("pause");
				}

				goto choiceLocation;

			case 3:
				cout << "Enter floppy name: ";
				gets(inputFloppyName);
				int y = 0;

				for (i = 0; i < 4; i++) {
					y += f[i].searchName(inputFloppyName);
				}

				cout << "Number of floppies with same name: " << y << endl;
				goto choiceLocation;

			case 4:
				break;

			default:
				cout << "Wrong choice" << endl;
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