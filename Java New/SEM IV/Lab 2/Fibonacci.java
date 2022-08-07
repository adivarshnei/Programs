// (8, 5). Write a program to take n from user and print n terms of Fibonacci 
// series

import java.util.Scanner;

public class Fibonacci {
   public static void printSeries(int limit) {
      int a0 = 0;
      int a1 = 1;
      int a2 = 0;

      System.out.print(a0 + " " + a1 + " ");

      for (int i = 2; i < limit; i++) {
         a2 = a1 + a0;
         a0 = a1;
         a1 = a2;

         System.out.print(a1 + " ");
      }
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter number of terms: ");
      int limit = sc.nextInt();

      System.out.println("Fibonacci Series upto " + limit + " terms is: ");

      printSeries(limit);

      sc.close();
   }
}
