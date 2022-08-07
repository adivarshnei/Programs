// (7, 4). Write a program to take radius from user and find area, perimeter of 
// cirle

import java.util.Scanner;

public class CircleOperations {
   public static float calcPerimeter(float radius) {
      return (2 * (float) Math.PI * radius);
   }

   public static float calcArea(float radius) {
      return ((float) Math.PI * radius * radius);
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter radius of the circle: ");
      float radius = sc.nextFloat();

      System.out.println("Radius of circle: " + radius);
      System.out.println("Perimeter of circle: " + calcPerimeter(radius));
      System.out.println("Area of circle: " + calcArea(radius));

      sc.close();
   }
}
