#include<iostream.h>
#include<process.h>

/*********************************************************************/

const int queueSize = 5;

/*********************************************************************/

class queue {
	private:
		int queueFront;
		int queueRear;
		int a[queueSize];

	public:
		queue();
		~queue();
		void enqueue(int);
		int dequeue();
		void displayData();
};

/*********************************************************************/

inline queue::queue() {
	queueFront = 0;
	queueRear = 0;
}

/*********************************************************************/

inline queue::~queue() {
	cout << "Destructing Object" << endl;
}

/*********************************************************************/

inline void queue::enqueue(int insert) {
	if (queueRear == queueSize) {
		cout << "Queue is Full" << endl;
	} else {
		a[queueRear++] = insert;
	}
}

/*********************************************************************/

inline int queue::dequeue() {
	int output = 0;

	if (queueFront == queueRear) {
		cout << "Queue is Empty" << endl;
	} else {
		output = a[queueFront++];
	}

	return output;
}

/*********************************************************************/

void queue::displayData() {
	cout<<endl;

	if (queueFront == queueRear) {
		cout << "Queue is Empty" << endl;
	} else {
		for (int i = queueFront; i < queueRear; i++) {
			cout << a[i] << "\t";
		}
	}
}

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		queue q;
		int queueValue, queueChoice;

		do {
			cout <<endl<< "1. Enqueue" << endl;
			cout << "2. Dequeue" << endl;
			cout << "3. Display" << endl;
			cout << "4. Exit" << endl;
			cin >> queueChoice;

			switch (queueChoice) {
				case 1:
					cout << endl << "Enter the value to be enqueued: ";
					cin >> queueValue;
					q.enqueue(queueValue);

					break;

				case 2:
					int dequeueStatusValue;
					dequeueStatusValue = q.dequeue();

					if (dequeueStatusValue != 0) {
						cout << endl << "The value dequeued is: " << dequeueStatusValue;
					}

					break;

				case 3:
					q.displayData();
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