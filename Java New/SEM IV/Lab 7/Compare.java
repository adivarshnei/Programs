// (28, 4). Write a program to override compareTo function of Comparable
// interface

import java.util.Scanner;

class Complex implements Comparable<Complex> {
   private int real;
   private int imag;

   Complex(Scanner sc) {
      System.out.print("Enter real part: ");
      this.real = sc.nextInt();
      System.out.print("Enter imaginary part: ");
      this.imag = sc.nextInt();
   }

   private int returnMagnitudeSqr() {
      return this.real * this.real + this.imag * this.imag;
   }

   public void printNumber() {
      System.out.print(real + " + " + imag + "i");
   }

   @Override
   public int compareTo(Complex complex) {
      if (this.returnMagnitudeSqr() == complex.returnMagnitudeSqr()) {
         this.printNumber();
         System.out.print(" is equal in magnitude to ");
         complex.printNumber();
      } else if (this.returnMagnitudeSqr() > complex.returnMagnitudeSqr()) {
         this.printNumber();
         System.out.print(" is greater in magnitude than ");
         complex.printNumber();
      } else {
         complex.printNumber();
         System.out.print(" is greater in magnitude than ");
         this.printNumber();
      }

      return 0;
   }
}

public class Compare {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.println("Enter first complex number: ");
      Complex complex1 = new Complex(sc);
      System.out.println("Enter second complex number: ");
      Complex complex2 = new Complex(sc);

      complex1.compareTo(complex2);

      sc.close();
   }
}
