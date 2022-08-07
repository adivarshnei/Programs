#include<iostream.h>
#include<process.h>

/*********************************************************************/

const int stackSize = 5;

/*********************************************************************/

class stack {
	private:
		int a[stackSize];
		int stackTop;

	public:
		stack();
		~stack();
		void pushOperation(int);
		int popOperation();
		void displayData();
};

/*********************************************************************/

inline stack::stack() {
	stackTop = -1;
}

/*********************************************************************/

inline stack::~stack() {
	cout << "Destructing Object" << endl;
}

/*********************************************************************/

inline void stack::pushOperation(int insert) {
	if (stackTop >= stackSize - 1) {
		cout << endl << "Stack is full" << endl;
	} else {
		stackTop++;
		a[stackTop] = insert;
	}
}

/*********************************************************************/

inline int stack::popOperation() {
	if (stackTop <= -1) {
		cout << endl << "Stack is empty" << endl;
		return -1;
	} else {
		int output = a[stackTop];
		stackTop--;

		return output;
	}
}

/*********************************************************************/

inline void stack::displayData() {
	cout << endl;

	for (int i = stackTop; i >= 0; i--) {
		cout << a[i] << " ";
	}
}

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		stack s;
		int stackChoice, stackValue;

		do {
			cout << endl << "1. Push" << endl;
			cout << "2. Pop" << endl;
			cout << "3. Display" << endl;
			cout << "4. Exit" << endl;
			cin >> stackChoice;

			switch (stackChoice) {
				case 1:
					cout << endl << "Enter the value to be pushed: ";
					cin >> stackValue;
					s.pushOperation(stackValue);

					break;

				case 2:
					int popStatusValue;
					popStatusValue = s.popOperation();

					if (popStatusValue != -1) {
						cout << endl << "The value popped is: " << popStatusValue << endl;
					}

					break;

				case 3:
					s.displayData();
					break;

				case 4:
					goto exitLoop;
			}

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
		}

	}

	cout << "Normal END" << endl;

	system("pause");
	return 0;
}