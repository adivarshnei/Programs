// (12, 4). Write a Java program that works as a simple calculator.

import java.util.Scanner;
import java.lang.Math;

public class Calculator {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      float num1;
      float num2;
      double result;
      double oppResult;
      int choice;

      do {

         System.out.println("1. Addition");
         System.out.println("2. Subtaction");
         System.out.println("3. Multiplication");
         System.out.println("4. Division");
         System.out.println("5. Exponent");
         System.out.println("6. Square Root");
         System.out.println("7. Exit");
         System.out.print("Enter Choice: ");
         choice = sc.nextInt();

         switch (choice) {
            case 1:
               System.out.print("Enter two numbers: ");
               num1 = sc.nextInt();
               num2 = sc.nextInt();

               result = num1 + num2;

               System.out.println(num1 + " + " + num2 + " = " + result);

               break;

            case 2:
               System.out.print("Enter two numbers: ");
               num1 = sc.nextInt();
               num2 = sc.nextInt();

               result = num1 - num2;
               oppResult = num2 - num1;

               System.out.println(num1 + " - " + num2 + " = " + result);
               System.out.println(num2 + " - " + num1 + " = " + oppResult);

               break;

            case 3:
               System.out.print("Enter two numbers: ");
               num1 = sc.nextInt();
               num2 = sc.nextInt();

               result = num1 * num2;

               System.out.println(num1 + " * " + num2 + " = " + result);

               break;

            case 4:
               System.out.print("Enter two numbers: ");
               num1 = sc.nextInt();
               num2 = sc.nextInt();

               if (num1 == 0 && num2 == 0) {
                  System.out.println("Cannot divide by zero.");
               }

               if (num2 != 0) {
                  result = num1 / num2;

                  System.out.println(num1 + " / " + num2 + " = " + result);
               }

               if (num1 != 0) {
                  oppResult = num2 / num1;

                  System.out.println(num2 + " / " + num1 + " = " + oppResult);
               }

               break;

            case 5:
               System.out.print("Enter two numbers: ");
               num1 = sc.nextInt();
               num2 = sc.nextInt();

               result = Math.pow(num1, num2);
               oppResult = Math.pow(num2, num1);

               System.out.println(num1 + " ^ " + num2 + " = " + result);
               System.out.println(num2 + " ^ " + num1 + " = " + oppResult);

               break;

            case 6:
               System.out.print("Enter a number: ");
               num1 = sc.nextInt();

               result = Math.sqrt(num1);

               System.out.println("sqrt(" + num1 + ") = " + result);

               break;

            case 7:
               break;

            default:
               System.out.println("Wrong Choice.");
               break;
         }
      } while (choice != 7);

      sc.close();
   }
}
