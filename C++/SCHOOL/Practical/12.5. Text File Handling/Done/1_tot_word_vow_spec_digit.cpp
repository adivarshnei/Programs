#include<process.h>
#include<fstream.h>
#include<ctype.h>
#include<stdio.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

class counters {
	public:
		unsigned int countWord;
		unsigned int countVowel;
		unsigned int countSpecChar;
		unsigned int countDigit;

		counters();
		~counters();
		void showCounters();
}; //class counters 

/*********************************************************************/

counters::counters() {
	countWord = 0;
	countVowel = 0;
	countSpecChar = 0;
	countDigit = 0;
} //counters::counters()

/*********************************************************************/

counters::~counters() {
	cout << endl << "Destructing Object" << endl;
} //counters::~counters()

/*********************************************************************/

inline void counters::showCounters() {
	cout << "Number of Words: " << countWord << endl;
	cout << "Number of Vowels: " << countVowel << endl;
	cout << "Number of Special Characters: " << countSpecChar - 1 << endl;
	cout << "Number of Digits: " << countDigit << endl;
} //inline void counters::showCounters()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		string inputString[200], ans, ch;
		counters countVal;

		ofstream outFile;
		outFile.open("p1.txt", ios::out);

		cout << "Enter line to enter into file: ";
		gets(inputString);

		outFile << inputString;

		outFile.close();

		ifstream infile;
		infile.open("p1.txt");
		infile.seekg(0);

		countVal.countWord++;

		while (!(infile.eof())) {
			infile.get(ch);

			if (ch == ' ') {
				countVal.countWord++;
			} else if (tolower(ch) == 'a' ||
				tolower(ch) == 'e' ||
				tolower(ch) == 'i' ||
				tolower(ch) == 'o' ||
				tolower(ch) == 'u') {
				countVal.countVowel++;
			} else if (isdigit(ch)) {
				countVal.countDigit++;
			} else if (isalpha(ch)) {
				cout << "";
			} else {
				countVal.countSpecChar++;
			} //End of extended if clause

		} //while (!(infile.eof()))

		countVal.showCounters();
		infile.close();

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