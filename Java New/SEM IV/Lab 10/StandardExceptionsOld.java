// import java.util.InputMismatchException;
// import java.util.Scanner;

// // class DivResult {
// //    public int quotient;
// //    public int remainder;

// //    DivResult() {
// //       this.quotient = 0;
// //       this.remainder = 0;
// //    }

// //    DivResult(int num1, int num2) {
// //       this.quotient = num1 / num2;
// //       this.remainder = num1 % num2;
// //    }

// //    public void display() {
// //       System.out.println("Quotient: " + this.quotient);
// //       System.out.println("Remainder: " + this.remainder);
// //    }
// // }

// public class StandardExceptionsOld {
//    public static void divZeroTestFunction(Scanner sc) {
//       int num1 = 0;
//       int num2 = 0;

//       System.out.print("Enter two numbers: ");

//       try {
//          num1 = sc.nextInt();
//          num2 = sc.nextInt();
//       } catch (InputMismatchException ex) {
//          System.out.println("InputMismatchException encountered");
//       }

//       DivResult result = new DivResult();

//       try {
//          result = new DivResult(num1, num2);
//          result.display();
//       } catch (ArithmeticException ex) {
//          System.out.println("Divide by Zero Error");
//       } finally {
//          result = null;
//       }
//    }

//    public static void printIntegerArray(int array[]) {
//       for (int element : array) {
//          System.out.print(element + "  ");
//       }

//       System.out.println();
//    }

//    public static void arrayOutOfBoundsTestFunction(Scanner sc) {
//       int integers[] = { 0, 1, 2, 3, 4 };
//       int index = 0;

//       System.out.print("Given array: ");

//       StandardExceptions.printIntegerArray(integers);

//       System.out.print("Enter index: ");

//       try {
//          index = sc.nextInt();
//       } catch (InputMismatchException ex) {
//          System.out.println("InputMismatchException encountered");
//       }

//       try {
//          System.out.println("Element at " + index + ": " + integers[index]);
//       } catch (ArrayIndexOutOfBoundsException ex) {
//          System.out.println("Array index out of bounds error");
//       }
//    }

//    public static void main(String[] args) {
//       Scanner sc = new Scanner(System.in);

//       StandardExceptions.divZeroTestFunction(sc);
//       StandardExceptions.arrayOutOfBoundsTestFunction(sc);

//       sc.close();
//    }
// }
