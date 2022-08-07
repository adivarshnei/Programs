// (5, 2). Write a program to illustrate user input

import java.util.Scanner;

public class ScannerInput {
   public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter a string: ");
      String str = sc.nextLine();
      String revstr = new String();

      for (int i = 0; i < str.length(); i++) {
         revstr = str.charAt(i) + revstr;
      }

      System.out.println("Original String: " + str);
      System.out.println("Reversed String: " + revstr);

      sc.close();
   }
}
