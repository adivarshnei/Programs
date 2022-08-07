import java.util.Scanner;

public class scanner_class {
   public static int sum(int a, int b) { return a + b; }

   public static void main(String args[]) {
      Scanner input = new Scanner(System.in);
      System.out.println("Enter a string");
      String string = input.nextLine();

      System.out.println("Enter a number");
      int number = input.nextInt();

      System.out.println("String: " + string);
      System.out.println("Number: " + number);

      System.out.println("Enter two numbers");
      int a = input.nextInt();
      int b = input.nextInt();
      
      System.out.println(a + " + " + b + " = " + scanner_class.sum(a, b));

      input.close();
   }
}

// terminal
