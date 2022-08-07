// // 1.

// package calc;

// import java.util.Scanner;

// public class Calculator {
//    private int operand1;
//    private int operand2;
//    private char operator;
//    private float result;

//    public Calculator() {
//       this.operand1 = 0;
//       this.operand2 = 0;
//       this.operator = '+';
//    }

//    public void getOperands(Scanner sc) {
//       System.out.print("Enter two numbers: ");
//       this.operand1 = sc.nextInt();
//       this.operand2 = sc.nextInt();
//    }

//    public void getOperation(Scanner sc) {
//       do {
//          System.out.print("Enter an operation (+, -, x, /): ");
//          this.operator = sc.next().charAt(0);
//       } while (this.operator != '+' && this.operator != '-' &&
//             this.operator != 'x' && this.operator != '/');
//    }

//    public void operate() {
//       switch (this.operator) {
//          case '+':
//             this.result = (float) this.operand1 + (float) this.operand2;
//             break;
//          case '-':
//             this.result = (float) this.operand1 - (float) this.operand2;
//             break;
//          case 'x':
//             this.result = (float) this.operand1 * (float) this.operand2;
//             break;
//          case '/':
//             if (this.operand2 != 0) {
//                this.result = (float) this.operand1 / (float) this.operand2;
//             } else {
//                System.out.println("Cannot Divide by Zero");
//                return;
//             }

//             break;
//       }

//       System.out.println(this.operand1 + " " + this.operator + " "
//             + this.operand2 + " = " + this.result);
//    }
// }
