// 1. Write a program to illustrate exceptions

import java.util.Scanner;
import java.util.InputMismatchException;

@FunctionalInterface
interface Divide {
   public ResultParams divideOperation(int num1, int num2);
}

class ResultParams {
   public int quotient;
   public int remainder;

   ResultParams(int quotient, int remainder) {
      this.quotient = quotient;
      this.remainder = remainder;
   }

   public void display() {
      System.out.println("Quotient: " + this.quotient);
      System.out.println("Remainder: " + this.remainder);
   }
}

public class DivZero {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      Divide divide = (int num1, int num2) -> {
         return new ResultParams(num1 / num2, num1 % num2);
      };

      int num1 = 1;
      int num2 = 1;

      System.out.print("Enter two numbers: ");

      try {
         num1 = sc.nextInt();
         num2 = sc.nextInt();
      } catch (InputMismatchException ex) {
         System.out.println("InputMismatchException encountered");
      }

      ResultParams result = new ResultParams(1, 1);

      try {
         result = divide.divideOperation(num1, num2);
      } catch (ArithmeticException ex) {
         System.out.println("ArithmeticException encountered");
      } finally {
         result.display();
      }

      sc.close();
   }
}
