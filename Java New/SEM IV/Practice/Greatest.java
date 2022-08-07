// 2. Write a program to find the greatest of three numbers

import java.util.Scanner;

public class Greatest {
   public static int returnGreatest(int a, int b, int c) {
      return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter three numbers: ");
      int a = sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();

      int greatest = returnGreatest(a, b, c);

      System.out.println("Out of " + a + ", " + b + ", " + c +
                         ", greatest number is " + greatest);

      sc.close();
   }
}
