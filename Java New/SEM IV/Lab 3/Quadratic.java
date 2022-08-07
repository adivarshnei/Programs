// (9, 1). Write a program that prints all real solutions to the quadratic
// equation ax^2 + bx + c = 0. Read in a, b, c and use the quadratic formula.
// If discriminant b^2 - 4ac is negative, display a message stating that there
// are no real solutions.

import java.util.Scanner;
import java.lang.Math;

public class Quadratic {
   private float a;
   private float b;
   private float c;
   private float discriminant;

   public void calculateDiscriminant() {
      this.discriminant = (this.b * this.b) - (4 * this.a * this.c);
   }

   public void displayRoots() {
      if (this.discriminant < 0) {
         System.out.println("Equation " + this.a + "x^2 + " + this.b +
               "x + " + this.c + " = 0 has no real roots.");
         return;
      }

      float root1;
      float root2;

      root1 = ((this.b * -1) + (float) Math.sqrt(this.discriminant)) /
            (2 * this.a);
      root2 = ((this.b * -1) - (float) Math.sqrt(this.discriminant)) /
            (2 * this.a);

      System.out.println("Roots of the equation " + this.a + "x^2 + " + this.b +
            "x + " + this.c + " = 0 are " + root1 + " and " + root2);

      return;
   }

   public static void main(String[] args) {
      Quadratic quadratic = new Quadratic();
      Scanner sc = new Scanner(System.in);

      System.out.println("For equation ax^2 + bx + c = 0");
      System.out.print("Enter value of a: ");
      quadratic.a = sc.nextFloat();
      System.out.print("Enter value of b: ");
      quadratic.b = sc.nextFloat();
      System.out.print("Enter value of c: ");
      quadratic.c = sc.nextFloat();

      quadratic.calculateDiscriminant();

      quadratic.displayRoots();

      sc.close();
   }
}
