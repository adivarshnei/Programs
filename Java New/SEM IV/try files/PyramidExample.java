/** This method is used to generate a pyramid made up of asterisks. */
public class PyramidExample {
   public static void main(String[] args) {
      for (int i = 0; i <= 5; i++) {
         for (int j = i; j <= 4; j++) {
            System.out.print("  ");
         }

         for (int j = 0; j <= 2 * i; j++) {
            System.out.print("* ");
         }

         System.out.println();
      }
   }
}