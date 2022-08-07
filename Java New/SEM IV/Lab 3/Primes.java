// (10, 2). Write a Java program that prompts the user for an integer and then 
// prints out all the prime numbers upto that integer.

import java.util.Scanner;

public class Primes {
   public static boolean isPrime(int num) {
      if (num == 2) {
         return true;
      } else if (num % 2 == 0) {
         return false;
      }

      for (int i = 3; i <= Math.sqrt(num); i += 2) {
         if (num % i == 0) {
            return false;
         }
      }

      return true;
   }

   public static void printPrimes(int num) {
      if (num < 2) {
         System.out.println("There are no prime numbers upto " + num);
         return;
      }

      System.out.println("Prime numbers upto " + num + " are: ");

      for (int i = 2; i <= num; i++) {
         if (isPrime(i)) {
            System.out.print(i + "  ");
         }
      }
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      int num;

      System.out.print("Enter a number: ");
      num = sc.nextInt();

      printPrimes(num);

      sc.close();
   }
}
