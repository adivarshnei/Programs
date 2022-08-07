// Program to check if a string is a palindrome

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String;
typedef int LoopVar;

enum Bool {
   YES = 1,
   NO = 2
};

Bool palindromeChk(String[]);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      String* inputString;
      Bool isPalindrome;

      cout << "Enter a string: ";
      gets(inputString);

      isPalindrome = palindromeChk(inputString);

      if (isPalindrome == YES) {
         cout << "String is a palindrome" << endl;
      } else if (isPalindrome == NO) {
         cout << "String is not a palindrome" << endl;
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

Bool palindromeChk(String inputString[]) {
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