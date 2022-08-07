#include<iostream.h>
#include<process.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

class convertExpression {
	private:
		string infix[100];
		string stackString[100];
		string postfix[100];
		int top;
		int r;

	public:
		~convertExpression();
		void convertExp();
		int input(char);
		int stack(char);
		int rank(char);
};

/*********************************************************************/

inline convertExpression::~convertExpression(){
	cout<<"Destructing Object"<<endl;
}

/*********************************************************************/

inline int convertExpression::input(char ch) {
	if (ch == '+' || ch == '-') {
		return 1;
	} else if (ch == '*' || ch == '/') {
		return 3;
	} else if (ch == '^') {
		return 6;
	} else if (isalpha(ch) && ch != 0) {
		return 7;
	} else if (ch == '(') {
		return 9;
	} else if (ch == ')') {
		return 0;
	} else {
		cout << "Invalid Input" << endl;
		exit(0);

		return 0;
	}
}

/*********************************************************************/

inline int convertExpression::stack(char ch) {
	if (ch == '+' || ch == '-') {
		return 2;
	} else if (ch == '*' || ch == '/') {
		return 4;
	} else if (ch == '^') {
		return 5;
	} else if (isalpha(ch) && ch != 0) {
		return 8;
	} else if (ch == '(') {
		return 0;
	} else {
		cout << "Invalid Input" << endl;
		exit(0);

		return 0;
	}
}

/*********************************************************************/

inline int convertExpression::rank(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
		return -1;
	} else if (isalpha(ch) != 0) {
		return 1;
	} else if (ch == '(') {
		return 0;
	} else {
		cout << "Invalid Input" << endl;
		exit(0);

		return 0;
	}
}

/*********************************************************************/

void convertExpression::convertExp() {
	cout << "Enter an infix expression: ";
	gets(infix);

	int l = strlen(infix);

	infix[l] = ')';
	infix[l + 1] = ' ';

	top = 1;
	stackString[top] = '(';

	r = 0;
	int x = -1;

	int i = 0;
	char next = infix[i];

	while (next != ' ') {
		while (input(next) < stack(stackString[top])) {
			if (top < 1) {
				cout << "Invalid input" << endl;
				exit(0);
			}

			postfix[++x] = stackString[top];
			top--;

			r = r + rank(postfix[x]);

			if (r < 1) {
				cout << "Invalid input" << endl;
				exit(0);
			}

		}

		if (input(next) != stack(stackString[top])) {
			stackString[++top] = next;
		} else {
			top--;
		}

		i++;
		next = infix[i];
	}

	postfix[++x] = ' ';

	if (r != 1 || top != 0) {
		cout << "Invalid input" << endl;
		exit(0);
	}

	cout << endl << endl << "The corresponding postfix expression is: ";
	puts(postfix);
}

unsigned long int count = 0;

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		convertExpression cE;
		cE.convertExp();

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