import java.math.BigInteger;
import java.util.Scanner;

public class BigFactorial {
   public static BigInteger factorial(long n) {
      BigInteger fact = BigInteger.ONE;

      for (int i = 2; i <= n; i++) {
         fact = fact.multiply(BigInteger.valueOf(i));
      }

      return fact;
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      long num = sc.nextLong();

      System.out.println(num + "! = " + factorial(num));

      sc.close();
   }
}
