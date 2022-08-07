// 4. Write a program to swap 2 numbers with and without using temporary
// variable

import java.util.Scanner;

public class Swaps {
   int num1;
   int num2;

   public static void swapWithTemp(Swaps sw) {
      int temp = sw.num1;
      sw.num1 = sw.num2;
      sw.num2 = temp;
   }

   public static void swapWithoutTemp(Swaps sw) {
      sw.num1 = sw.num1 + sw.num2;
      sw.num2 = sw.num1 - sw.num2;
      sw.num1 = sw.num1 - sw.num2;
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      Swaps sw1 = new Swaps();
      Swaps sw2 = new Swaps();

      System.out.print("Enter two numbers: ");
      sw1.num1 = sw2.num1 = sc.nextInt();
      sw1.num2 = sw2.num2 = sc.nextInt();

      System.out.println("Numbers before swapping: ");
      System.out.println("num1 = " + sw1.num1 + ", num2 = " + sw1.num2);
      swapWithTemp(sw1);
      swapWithoutTemp(sw2);

      System.out.println("Numbers after swapping with temp: ");
      System.out.println("num1 = " + sw1.num1 + ", num2 = " + sw1.num2);

      System.out.println("Numbers after swapping without temp: ");
      System.out.println("num1 = " + sw2.num1 + ", num2 = " + sw2.num2);

      sc.close();
   }
}
