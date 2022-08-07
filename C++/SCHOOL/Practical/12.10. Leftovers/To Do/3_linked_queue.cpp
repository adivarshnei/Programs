#include<iostream.h>
#include<process.h>

/*********************************************************************/

typedef struct queueNode {
	int value;
	queueNode * next;
}; //typedef struct queueNode

/*********************************************************************/

class queue {
	private:
		queueNode * rear;
		queueNode * front;

	public:
		queue();
		~queue();
		void enqueue();
		void dequeue();
		void displayData();
}; //class queue

/*********************************************************************/

queue::queue() {
	front = NULL;
	rear = NULL;
} //queue::queue()

/*********************************************************************/

queue::~queue() {
	while (front != NULL) {
		queueNode * temp = front;
		front = front -> next;
		delete temp;
	} //while (front != NULL)
} //queue::~queue()

/*********************************************************************/

void queue::enqueue() {
	queueNode * temp;
	temp = new queueNode;
	cout << "Data: ";
	cin >> temp -> value;
	temp -> next = NULL;

	if (rear == NULL) {
		rear = temp;
		front = temp;
	} else {
		rear -> next = temp;
		rear = temp;
	} //End of extended if clause
} //void queue::enqueue()

/*********************************************************************/

void queue::dequeue() {
	if (front != NULL) {
		queueNode * temp = front;
		cout << "Elemet deleted: " << temp -> value << endl;
		front = front -> next;
		delete temp;

		if (front == NULL) {
			rear = NULL;
		} //if (front == NULL)

	} else {
		cout << endl << "Queue is empty" << endl;
	} //End of extended if clause
} //void queue::dequeue()

/*********************************************************************/

void queue::displayData() {
	queueNode * temp = front;

	while (temp != NULL) {
		cout << temp -> value << endl;
		temp = temp -> next;
	} //while (temp != NULL)
} //void queue::displayData()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		queue q;
		int choice;

		do {
			switchChoice: 
			cout << endl << "1. Enqueue" << endl;
			cout << "2. Dequeue" << endl;
			cout << "3. Display Queue" << endl;
			cout << "4. Exit" << endl;
			cin >> choice;

			switch (choice) {
				case 1:
					q.enqueue();
					break;

				case 2:
					q.dequeue();
					break;

				case 3:
					q.displayData();
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