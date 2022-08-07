#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;
int main() {
	map < char, long > chars;
	cout << "chardist - Count character distributions" << endl;
	cout << "Type some text. Press ctrl-D to quit." << endl;
	char c;
	while (cin.get(c)) {
		c = tolower(static_cast < unsigned char > (c));
		chars[c] = chars[c] + 1;
	}
	cout << "Character distribution: " << endl;
	string alphabet("abcdefghijklmnopqrstuvwxyz");
	for (string::iterator letter_index = alphabet.begin(); letter_index != alphabet.end(); letter_index++) {
		if (chars[ * letter_index] != 0) {
			cout << char(toupper( * letter_index)) <<
				":" << chars[ * letter_index] <<
				"\t" << endl;
		}
	}
	return 0;
}