import java.util.Scanner;
import java.util.InputMismatchException;

public class OutOfBounds {
   public static void printIntegerArray(int array[]) {
      for (int element : array) {
         System.out.print(element + "\t");
      }

      System.out.println();
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      int integers[] = {0, 1, 2, 3, 4};
      int index = 0;

      OutOfBounds.printIntegerArray(integers);

      System.out.print("Enter index: ");

      try {
         index = sc.nextInt();
      } catch (InputMismatchException ex) {
         System.out.println("InputMismatchException encountered");
      }

      try {
         System.out.println("Element at " + index + ": " + integers[index]);
      } catch (ArrayIndexOutOfBoundsException ex) {
         System.out.println("ArrayIndexOutOfBoundsException encountered");
      }

      sc.close();
   }
}
