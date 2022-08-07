public class Collatz {
   public static long collatz(long n) {
      long i = n;
      int steps = 0;

      while (i != 1) {
         if (i % 2 == 0) {
            i /= 2;
         } else {
            i *= 3;
            i += 1;
         }

         // System.out.println(i);

         steps++;
      }

      return steps;
   }

   public static void main(String[] args) {
      for (long i = 2; i < 100; i++) {
         System.out.println("[" + i + "] -> " + Collatz.collatz(i));
      }
   }
}
