// Write a program to check palindrome for a) string b) number

#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 50

using namespace std;

typedef int LoopVar;
typedef char String;

enum Bool { YES = 1, NO = 2 };

int shouldRepeat;

Bool numPalindromeChk(long int number) {
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

Bool strPalindromeChk(String inputString[MAX_STRING]) {
   LoopVar i = 0;
   LoopVar j = strlen(inputString) - 1;
   Bool isPalindrome = YES;

   String reverseString[MAX_STRING];

   strcpy(reverseString, inputString);
   strrev(reverseString);

   cout << "Original String: " << inputString << endl;

   while (i < strlen(inputString) - 1) {
      if (inputString[i] != inputString[j]) {
         isPalindrome = NO;
         break;
      }

      i++;
      j--;
   }

   cout << "Reversed String: " << reverseString << endl;

   return isPalindrome;
}

int main(void) {
   system("cls");

   while (1) {
      int choice;
      long int number;
      String inputString[MAX_STRING];
      Bool isPalindrome;

      do {
         cout << "1. Number Palindrome Check" << endl;
         cout << "2. String Palindrome Check" << endl;
         cout << "3. Exit" << endl;
         cout << "Enter Choice: ";
         cin >> choice;
         cin.ignore(256, '\n');

         switch (choice) {
         case 1:
            cout << "Enter a number: ";
            cin >> number;
            cin.ignore(256, '\n');

            isPalindrome = numPalindromeChk(number);

            if (isPalindrome == YES) {
               cout << "Number is a palindrome" << endl;
            } else if (isPalindrome == NO) {
               cout << "Number is not a palindrome" << endl;
            }

            break;

         case 2:
            cout << "Enter a string: ";
            cin.getline(inputString, MAX_STRING);

            isPalindrome = strPalindromeChk(inputString);

            if (isPalindrome == YES) {
               cout << "String is a palindrome" << endl;
            } else if (isPalindrome == NO) {
               cout << "String is not a palindrome" << endl;
            }

            break;

         case 3:
            break;

         default:
            cout << "Wrong Option Entered" << endl;
            break;
         }
      } while (choice != 3);

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
