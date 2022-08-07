// (27, 3). Write a program to use final variables, final methods and final
// classes

class FinalVarsMethods {
   // Cannot be modified
   private final int finalVar = 10;

   // Cannot be overridden
   public final void finalMethod() {
      System.out.println("In Final Method");
      System.out.println("Final Var: " + finalVar);
   }
}

// Cannot be extended
final class FinalClass {
   private int testVar = 5;

   public void display() {
      System.out.println("In Final Class");
      System.out.println("Test Var: " + testVar);
   }
}

public class Final {
   public static void main(String[] args) {
      FinalVarsMethods finalVarsMethods = new FinalVarsMethods();
      FinalClass finalClass = new FinalClass();

      finalVarsMethods.finalMethod();
      finalClass.display();
   }
}
