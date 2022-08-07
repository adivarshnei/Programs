// (25, 1). Write a program to show concept of multiple inheritance through
// implementation of interfaces in a class

import java.util.Scanner;

interface GetOperations {
   public void getOperand1(Scanner sc);

   public void getOperand2(Scanner sc);

   public void getOperator(Scanner sc);
}

interface ReturnResults {
   public boolean executeOperation();
}

class Operation implements GetOperations, ReturnResults {
   private int operand1;
   private int operand2;
   private char operator;
   private float result;

   @Override
   public void getOperand1(Scanner sc) {
      System.out.print("Enter first operand: ");
      this.operand1 = sc.nextInt();
   }

   @Override
   public void getOperand2(Scanner sc) {
      System.out.print("Enter second operand: ");
      this.operand2 = sc.nextInt();
   }

   @Override
   public void getOperator(Scanner sc) {
      System.out.print("Enter operator (+, -, x, /): ");
      this.operator = sc.next().charAt(0);
   }

   @Override
   public boolean executeOperation() {
      boolean validOperation = false;

      switch (this.operator) {
         case '+':
            this.result = (float) this.operand1 + (float) this.operand2;
            validOperation = true;
            break;

         case '-':
            this.result = (float) this.operand1 - (float) this.operand2;
            validOperation = true;
            break;

         case 'x':
            this.result = (float) this.operand1 * (float) this.operand2;
            validOperation = true;
            break;

         case '/':
            this.result = (float) this.operand1 / (float) this.operand2;
            validOperation = true;
            break;

         default:
            System.out.println("Invalid Operator");
            break;
      }

      return validOperation;
   }

   public void display() {
      System.out.println(this.operand1 + " " + this.operator + " "
            + this.operand2 + " = " + this.result);
   }
}

public class MultipleInheritance {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      Operation operation = new Operation();

      operation.getOperand1(sc);
      operation.getOperand2(sc);
      operation.getOperator(sc);

      while (true) {
         if (!operation.executeOperation()) {
            operation.getOperator(sc);
         } else {
            break;
         }
      }

      operation.display();

      sc.close();
   }
}
