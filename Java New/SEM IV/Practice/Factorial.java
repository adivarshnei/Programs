// 3. Write a program to find factorial of a number using functions

import java.util.Scanner;

public class Factorial {
   public static long factorial(long n) {
      return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter a number: ");
      long num = sc.nextLong();

      long fact = factorial(num);

      System.out.println(num + "! = " + fact);

      sc.close();
   }
}
