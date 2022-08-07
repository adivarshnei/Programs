// Write a program to demonstrate file handling

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int shouldRepeat;

void writeToFile() {
   char inputChar;
   ofstream fout;

   cout << "Enter into file character by character (; ends entry)): ";
   inputChar = _getch();

   while (inputChar != ';') {
      fout.open("30.txt", ios::app);
      fout.put(inputChar);
      fout.close();
      cout << inputChar;
      inputChar = _getch();
   }
}

int main(void) {
   system("cls");

   while (1) {
      writeToFile();

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;
      cin.ignore(256, '\n');

      if (shouldRepeat == 1) {
         continue;
      } else {
         cout << endl << "END" << endl;
         break;
      }
   }

   system("pause");
   return 0;
}
