// (31, 1). Write a program to handle ArithmeticException and
// ArrayOutOfBoundsException

import java.util.InputMismatchException;
import java.util.Scanner;

class DivResult {
   public int quotient;
   public int remainder;

   public DivResult() {
      this.quotient = 0;
      this.remainder = 0;
   }

   public DivResult(int num1, int num2) {
      this.quotient = num1 / num2;
      this.remainder = num1 % num2;
   }

   public void display() {
      System.out.println("Quotient: " + this.quotient);
      System.out.println("Remainder: " + this.remainder);
   }
}

public class StandardExceptions {
   public static void divZeroTestFunction(Scanner sc)
         throws ArithmeticException {
      int num1 = 0;
      int num2 = 0;

      System.out.print("Enter two numbers: ");

      try {
         num1 = sc.nextInt();
         num2 = sc.nextInt();
      } catch (InputMismatchException ex) {
         System.out.println("InputMismatchException encountered");
      }

      DivResult result = new DivResult();

      result = new DivResult(num1, num2);
      result.display();
   }

   public static void arrayOutOfBoundsTestFunction(Scanner sc)
         throws ArrayIndexOutOfBoundsException {
      int integers[] = { 0, 1, 2, 3, 4 };
      int index = 0;

      System.out.print("Given Array: ");

      for (int integer : integers) {
         System.out.print(integer + "  ");
      }

      System.out.println();

      try {
         System.out.print("Enter index: ");
         index = sc.nextInt();
      } catch (InputMismatchException ex) {
         System.out.println("InputMismatchException encountered");
      }

      System.out.println("Element at " + index + ": " + integers[index]);
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      try {
         StandardExceptions.divZeroTestFunction(sc);
      } catch (ArithmeticException ex) {
         System.out.println("Divide by Zero Error");
      }

      try {
         StandardExceptions.arrayOutOfBoundsTestFunction(sc);
      } catch (ArrayIndexOutOfBoundsException ex) {
         System.out.println("Array Index Out of Bounds Error");
      }

      sc.close();
   }
}
