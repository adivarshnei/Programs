// (15, 3). Write a program that reads in two floating-point numbers and tests
// whether they are same up to three decimal places

import java.lang.Math;
import java.util.Scanner;

public class NumberComparer {
   static void compareFloats(float num1, float num2) {
      int tempNum1 = (int) (num1 * Math.pow(10, 3));
      int tempNum2 = (int) (num2 * Math.pow(10, 3));

      if (tempNum1 == tempNum2) {
         System.out.println(num1 + " and " + num2 +
               " are same upto three decimal places");
      } else {
         System.out.println(num1 + " and " + num2 +
               " are not same upto three decimal places");
      }
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter two floating point numbers: ");
      float num1 = sc.nextFloat();
      float num2 = sc.nextFloat();

      NumberComparer.compareFloats(num1, num2);

      sc.close();
   }
}
