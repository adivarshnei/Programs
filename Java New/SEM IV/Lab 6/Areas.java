// (22, 3). Write a program to calculate area of different geometrical figures
// (circle, rectangle, square, triangle) using function overloading

import java.util.Scanner;
import java.lang.Math;

public class Areas {
   static float area(float radius) {
      return ((float) Math.PI) * radius * radius;
   }

   static float area(float length, float breadth) {
      return length * breadth;
   }

   static float area(double side) {
      return (float) (side * side);
   }

   static float area(double base, double height) {
      return (float) (0.5 * base * height);
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter radius of a circle: ");
      float radius = sc.nextFloat();

      System.out.print("Enter sides of a rectangle: ");
      float length = sc.nextFloat();
      float breadth = sc.nextFloat();

      System.out.print("Enter side of a square: ");
      double side = sc.nextDouble();

      System.out.print("Enter base and height of a triangle: ");
      double base = sc.nextDouble();
      double height = sc.nextDouble();

      System.out.println("Area of a circle with radius " + radius + " = "
            + Areas.area(radius));
      System.out.println("Area of a rectangle with sides " + length + " and "
            + breadth + " = " + Areas.area(length, breadth));
      System.out.println("Area of a square with side " + side + " = "
            + Areas.area(side));
      System.out.println("Area of a triagle with base " + base + " and height "
            + height + " = " + Areas.area(base, height));

      sc.close();
   }
}
