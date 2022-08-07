#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

//*************************************************************************

typedef char string;

//*************************************************************************

class library {
	private:
		int bookNumber;
		string bookName[20];
		string author[20];
		float price;
		unsigned int noOfCopies;
		unsigned int noOfCopiesIssued;

	public:
		void getBookData();
		void bookIssue();
		void bookReturn();
		int bookAvailabilityCheck();
		void printByNumber(int);
		void showBookData();
		int nameChk(string[]);
};

//*************************************************************************

inline void library::getBookData() {
	cout << "Enter the book number: ";
	cin >> bookNumber;
	cout << "Enter the book name: ";
	gets(bookName);
	cout << "Enter the author name: ";
	gets(author);
	cout << "Enter the price: ";
	cin >> price;
	cout << "Enter the number of books: ";
	cin >> noOfCopies;
	noOfCopiesIssued = 0;
}

//*************************************************************************

inline int library::bookAvailabilityCheck() {
	if (noOfCopies - noOfCopiesIssued > 0) {
		return 1;
	} else {
		return 0;
	}
}

//*************************************************************************

inline void library::bookIssue() {
	int x = bookAvailabilityCheck();

	if (x == 0) {
		cout << "Book is unavailable" << endl;
	} else {
		cout << "Book is available. Issuing book." << endl;
		noOfCopiesIssued++;
	}
}

//*************************************************************************

inline void library::bookReturn() {
	cout << "Book Returned" << endl;
	noOfCopiesIssued--;
}

//*************************************************************************

inline void library::printByNumber(int inputBookNumber) {
	if (inputBookNumber == bookNumber) {
		showBookData();
	}
}

//*************************************************************************

inline void library::showBookData() {
	cout << "Book number: " << bookNumber << endl;
	cout << "Book name: " << bookName << endl;
	cout << "Author: " << author << endl;
	cout << "Price: " << price << endl;
	cout << "Books available: " << noOfCopies - noOfCopiesIssued << endl;
}

//*************************************************************************

inline int library::nameChk(string inputBookName[]) {
	if (strcmp(inputBookName, bookName) == 0) {
		return 1;
	} else {
		return 0;
	}
}

//*************************************************************************

long count = 0;

//*************************************************************************

int main(void) {
	int rep = 1;

	while (rep == 1) {
		system("cls");

		int choice, i, x;
		library l[5];
		string inputBookName[20];
		int inputBookNumber;

		for (i = 0; i < 5; i++) {
			l[i].getBookData();
		}

		choiceLocation:
		cout << "1. Return book" << endl;
		cout << "2. Withdraw book" << endl;
		cout << "3. Find book by number" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter the book name: ";
				gets(inputBookName);

				for (i = 0; i < 5; i++) {
					x = l[i].nameChk(inputBookName);

					if (x == 1) {
						l[i].bookReturn();
					} else if (x == 0) {
						cout << "This book is not of the library." << endl;
					}

				}

				goto choiceLocation;
				break;

			case 2:
				cout << "Enter the book name: ";
				gets(inputBookName);

				for (i = 0; i < 5; i++) {
					x = l[i].nameChk(inputBookName);

					if (x == 1) {
						l[i].bookIssue();
					} else if (x == 0) {
						cout << "This book is not in the library." << endl;
					}

				}

				goto choiceLocation;
				break;

			case 3:
				cout << "Enter the book number: ";
				cin >> inputBookNumber;

				for (i = 0; i < 5; i++) {
					l[i].printByNumber(inputBookNumber);
				}

				goto choiceLocation;
				break;

			case 4:
				break;

			default:
				cout << "Wrong Choice";
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