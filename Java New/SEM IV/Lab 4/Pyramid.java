// (17, 5). Write a program to make such a pattern like a pyramid with a number
// which will repeat the number in the same row.

import java.util.Scanner;

public class Pyramid {
   static void printPyramid(int height) {
      for (int i = 0; i <= height; i++) {
         for (int j = i; j < height; j++) {
            System.out.print(" ");
         }

         for (int k = 0; k < 2 * i - 1; k++) {
            System.out.print(i);
         }

         System.out.println();
      }
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter height of pyramid: ");
      int height = sc.nextInt();

      Pyramid.printPyramid(height);

      sc.close();
   }
}
