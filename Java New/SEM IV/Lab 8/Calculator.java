// (30, 1). You are given an interface AdvancedArithmetic which contains a
// method signature int divisior_sum(int n). You need to write a class called
// MyCalculator which implements the interface. divisorSum() function just takes
// an integer as input and returns the sum of all its divisors. The value of n
// will be at most 1000

import java.util.Scanner;

interface AdvancedArithmetic {
   int divisior_sum(int n);
}

class MyCalculator implements AdvancedArithmetic {
   @Override
   public int divisior_sum(int n) {
      int sum = 0;

      for (int i = 1; i <= n; i++) {
         if (n % i == 0) {
            sum += i;
         }
      }

      return sum;
   }
}

public class Calculator {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      MyCalculator myCalculator = new MyCalculator();

      System.out.print("Enter a number: ");
      int n = sc.nextInt();
      int sum = myCalculator.divisior_sum(n);

      System.out.println("Sum of divisors of " + n + " is " + sum);

      sc.close();
   }
}
