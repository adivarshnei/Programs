// (24, 5). Write a program to implement interfaces

import java.lang.Math;
import java.util.Scanner;

interface AreaVolumeFormulae {
   public float surfaceArea();

   public float volume();

   public static final float PI = 3.14159265f;
}

class Cone implements AreaVolumeFormulae {
   private float radius;
   private float height;

   Cone(float radius, float height) {
      this.radius = radius;
      this.height = height;
   }

   @Override
   public float surfaceArea() {
      float slantHeight = (float) Math.sqrt(this.radius * this.radius
            + this.height * this.height);
      return AreaVolumeFormulae.PI * this.radius * (this.radius + slantHeight);
   }

   @Override
   public float volume() {
      return (1.0f / 3.0f) * AreaVolumeFormulae.PI * this.radius * this.radius
            * this.height;
   }
}

class Cylinder implements AreaVolumeFormulae {
   private float radius;
   private float height;

   Cylinder(float radius, float height) {
      this.radius = radius;
      this.height = height;
   }

   @Override
   public float surfaceArea() {
      return 2 * AreaVolumeFormulae.PI * this.radius * (this.radius
            + this.height);
   }

   @Override
   public float volume() {
      return AreaVolumeFormulae.PI * this.radius * this.radius * this.height;
   }
}

public class Interfaces {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int choice;

      do {
         System.out.println("1. Find surface area and volume of cone");
         System.out.println("2. Find surface area and volume of cylinder");
         System.out.println("3. Exit");
         System.out.print("Enter Choice: ");
         choice = sc.nextInt();

         switch (choice) {
            case 1: {
               System.out.print("Enter radius: ");
               float radius = sc.nextFloat();
               System.out.print("Enter height: ");
               float height = sc.nextFloat();

               Cone cone = new Cone(radius, height);

               System.out.println("Surface Area of cone is: "
                     + cone.surfaceArea());
               System.out.println("Volume of cone is: " + cone.volume());
            }

               break;

            case 2: {
               System.out.print("Enter radius: ");
               float radius = sc.nextFloat();
               System.out.print("Enter height: ");
               float height = sc.nextFloat();

               Cylinder cylinder = new Cylinder(radius, height);

               System.out.println("Surface Area of cylinder is: "
                     + cylinder.surfaceArea());
               System.out.println("Volume of cylinder is: "
                     + cylinder.volume());
            }

               break;

            case 3:
               break;

            default:
               System.out.println("Wrong choice");
               break;
         }
      } while (choice != 3);

      sc.close();
   }
}
