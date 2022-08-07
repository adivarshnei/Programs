// (4, 1). Write a program to illustrate command line arguments

public class CmdArgs {
   public static void main(String args[]) {
      if (args.length == 3) {
         float x = Float.parseFloat(args[0]);
         String op = args[1];
         float y = Float.parseFloat(args[2]);
         float res = 0;

         if (op.equals("+")) {
            res = x + y;
         } else if (op.equals("-")) {
            res = x - y;
         } else if (op.equals("x")) {
            res = x * y;
         } else if (op.equals("/")) {
            if (y != 0) {
               res = x / y;
            } else {
               System.out.println("Divide by Zero Error");
            }
         }

         if (!(op.equals("/") && y == 0)) {
            System.out.println(x + " " + op + " " + y + " = " + res);
         }
      } else {
         System.out.println("Invalid command line arguments entered");
      }
   }
}
