#include <fstream>
#include <iostream>
#include <cctype>

int main(void) {
   char ch;
   long long int sum = 0;

   std::ifstream fin;
   fin.open("text.txt");

   while (!fin.eof()) {
      fin.get(ch);

      if (isdigit(ch)) {
         long long int num = ch - '0';

         while (fin.get(ch)) {
            if (fin.eof()) {
               break;
            }
            if (ch == ' ' || ch == '\n') {
               break;
            } else {
               num *= 10;
               num += ch - '0';
            }
         }

         sum += num;
      }
   }

   fin.close();

   std::ofstream fout;
   fout.open("text.txt", std::ios::app);
   fout << "\n" << sum;
   fout.close();

   return 0;
}
