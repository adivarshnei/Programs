// Program to check if a number is a palindrome

#include <iostream.h>
#include <stdlib.h>

enum Bool {
   YES = 1,
   NO = 2
};

Bool palindromeChk(long int);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      long int number;
      Bool isPalindrome;

      cout << "Enter a number: ";
      cin >> number;

      isPalindrome = palindromeChk(number);

      if (isPalindrome == YES) {
         cout << "Number is a palindrome" << endl;
      } else if (isPalindrome == NO) {
         cout << "Number is not a palindrome" << endl;
      }

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;

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

Bool palindromeChk(long int number) {
   long int revNum = 0;
   long int temp;

   cout << "Original Number: " << number << endl;

   temp = number;

   while (temp > 0) {
      revNum *= 10;
      revNum += temp % 10;
      temp /= 10;
   }

   cout << "Reverse Number: " << revNum << endl;

   if (revNum == number) {
      return YES;
   } else {
      return NO;
   }
}