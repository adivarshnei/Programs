// (11, 3). Write a program that checks whether the given string is a palindrome
// or not.

import java.util.Scanner;

public class Palindrome {
   public static void palindromeCheck(String string) {
      boolean isPalindrome = true;

      for (int i = 0; i < (string.length() / 2) + 1; i++) {
         if (string.charAt(i) != string.charAt(string.length() - i - 1)) {
            isPalindrome = false;
            break;
         }
      }

      if (isPalindrome) {
         System.out.println("String \"" + string + "\" is a palindrome.");
      } else {
         System.out.println("String \"" + string + "\" is not a palindrome.");
      }
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      String string = new String();

      System.out.print("Enter a string: ");
      string = sc.nextLine();

      palindromeCheck(string);

      sc.close();
   }
}
