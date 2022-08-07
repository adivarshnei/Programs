#include<iostream.h>
#include<process.h>

/*********************************************************************/

typedef struct stackNode {
	int value;
	stackNode * next;
}; //typedef struct stackNode

class stack {
	private:
		stackNode * top;

	public:
		stack();
		~stack();
		void stackPush();
		void stackPop();
		void displayData();
}; //class stack 

stack::stack() {
	top = NULL;
} //stack::stack()

stack::~stack() {
	while (top != NULL) {
		stackNode * temp = top;
		top = top -> next;

		delete temp;
	} //while (top != NULL)
} //stack::~stack()

void stack::stackPush() {
	stackNode * temp;
	temp = new stackNode;

	cout << "Enter value: ";
	cin >> temp -> value;

	temp -> next = top;
	top = temp;
} //void stack::stackPush()

void stack::stackPop() {
	if (top != NULL) {
		stackNode * temp = top;
		top = top -> next;

		cout << "Element popped: " << temp -> value << endl;

		delete temp;
	} else {
		cout << endl << "Stack is empty" << endl;
	} //End of extended if clause
} //void stack::stackPop()

void stack::displayData() {
	stackNode * temp = top;
	cout << "Stack is: ";

	while (temp != NULL) {
		cout << temp -> value << "\t";
		temp = temp -> next;
	} //while (temp != NULL)

} //void stack::displayData()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		stack s;
		int choice;

		do {
			switchChoice: 
			cout << endl << "1. Push" << endl;
			cout << "2. Pop" << endl;
			cout << "3. Display Stack" << endl;
			cout << "4. Exit" << endl;
			cin >> choice;

			switch (choice) {
				case 1:
					s.stackPush();
					break;

				case 2:
					s.stackPop();
					break;

				case 3:
					s.displayData();
					break;

				case 4:
					goto exitLoop;
					break;

				default:
					goto switchChoice;
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