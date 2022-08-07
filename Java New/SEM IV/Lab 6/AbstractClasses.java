// (23, 4). Write a program to represent Abstract class with example

import java.util.Scanner;

abstract class Operation {
   protected int operator1;
   protected int operator2;

   Operation(int operator1, int operator2) {
      this.operator1 = operator1;
      this.operator2 = operator2;
   }

   public abstract float performOperation();
}

class Addition extends Operation {
   Addition(int operator1, int operator2) {
      super(operator1, operator2);
   }

   @Override
   public float performOperation() {
      return this.operator1 + this.operator2;
   }
}

class Subtraction extends Operation {
   Subtraction(int operator1, int operator2) {
      super(operator1, operator2);
   }

   @Override
   public float performOperation() {
      return this.operator1 - this.operator2;
   }
}

class Multiplication extends Operation {
   Multiplication(int operator1, int operator2) {
      super(operator1, operator2);
   }

   @Override
   public float performOperation() {
      return this.operator1 * this.operator2;
   }
}

class Division extends Operation {
   Division(int operator1, int operator2) {
      super(operator1, operator2);
   }

   @Override
   public float performOperation() {
      return this.operator1 / this.operator2;
   }
}

public class AbstractClasses {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int choice;

      do {
         System.out.println("1. Addition");
         System.out.println("2. Subtraction");
         System.out.println("3. Multiplication");
         System.out.println("4. Division");
         System.out.println("5. Exit");
         System.out.print("Enter Choice: ");
         choice = sc.nextInt();

         switch (choice) {
            case 1: {
               System.out.print("Enter operator 1: ");
               int operator1 = sc.nextInt();
               System.out.print("Enter operator 2: ");
               int operator2 = sc.nextInt();

               Addition addition = new Addition(operator1, operator2);

               System.out.println(operator1 + " + " + operator2 + " = "
                     + addition.performOperation());
            }
               break;

            case 2: {
               System.out.print("Enter operator 1: ");
               int operator1 = sc.nextInt();
               System.out.print("Enter operator 2: ");
               int operator2 = sc.nextInt();

               Subtraction subtraction = new Subtraction(operator1, operator2);

               System.out.println(operator1 + " - " + operator2 + " = "
                     + subtraction.performOperation());
            }
               break;

            case 3: {
               System.out.print("Enter operator 1: ");
               int operator1 = sc.nextInt();
               System.out.print("Enter operator 2: ");
               int operator2 = sc.nextInt();

               Multiplication multiplication = new Multiplication(operator1,
                     operator2);

               System.out.println(operator1 + " * " + operator2 + " = "
                     + multiplication.performOperation());
            }
               break;

            case 4: {
               System.out.print("Enter operator 1: ");
               int operator1 = sc.nextInt();
               System.out.print("Enter operator 2: ");
               int operator2 = sc.nextInt();

               Division division = new Division(operator1, operator2);

               try {
                  System.out.println(operator1 + " / " + operator2 + " = "
                        + division.performOperation());
               } catch (ArithmeticException ex) {
                  System.out.println("Cannot Divide by Zero");
               }
            }
               break;

            case 5:
               break;

            default:
               System.out.println("Wrong Choice");
               break;
         }
      } while (choice != 5);

      sc.close();
   }
}
