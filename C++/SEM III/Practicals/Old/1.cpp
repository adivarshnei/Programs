/*
Q1. Write a program to check number palindrome and string palindrome.
*/

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int LoopVar;
typedef char String;

enum Bool {
   YES = 1,
   NO = 2
};

Bool numPalindromeChk(long int);
Bool strPalindromeChk(String[]);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      int choice;
      Bool isCompleted = NO;

      long int number;
      String* inputString;

      Bool isPalindrome;

      do {
         cout << "1. Number Palindrome Check" << endl;
         cout << "2. String Palindrome Check" << endl;
         cout << "3. Exit" << endl;
         cout << "Enter Choice" << endl;
         cin >> choice;

         switch (choice) {
         case 1:
            cout << "Enter a number: ";
            cin >> number;

            isPalindrome = numPalindromeChk(number);

            if (isPalindrome == YES) {
               cout << "Number is a palindrome" << endl;
            } else if (isPalindrome == NO) {
               cout << "Number is not a palindrome" << endl;
            }

            isCompleted = YES;
            break;

         case 2:
            cout << "Enter a string: ";
            gets(inputString);

            isPalindrome = strPalindromeChk(inputString);

            if (isPalindrome == YES) {
               cout << "String is a palindrome" << endl;
            } else if (isPalindrome == NO) {
               cout << "String is not a palindrome" << endl;
            }

            isCompleted = YES;
            break;

         case 3:
            isCompleted = YES;
            break;

         default:
            cout << "Wrong Option Entered" << endl;
            break;
         }
      } while (isCompleted == NO);

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

Bool strPalindromeChk(String inputString[]) {
   LoopVar i = 0;
   LoopVar j = strlen(inputString) - 1;
   Bool isPalindrome = YES;

   String* reverseString;

   strcpy(reverseString, inputString);
   strrev(reverseString);

   cout << "Original String: " << inputString << endl;

   while (i < strlen(inputString) + 1) {
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