// (6, 3). Write a program to take n from user and print its multiplication table

import java.util.Scanner;

public class MultiplicationTable {
   public static void printTable(int num, int lim) {
      for (int i = 0; i < lim + 1; i++) {
         System.out.println(num + " * " + i + " = " + (num * i));
      }
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter a number: ");
      int num = sc.nextInt();
      System.out.print("Enter number of iterations of table: ");
      int lim = sc.nextInt();

      printTable(num, lim);

      sc.close();
   }
}
