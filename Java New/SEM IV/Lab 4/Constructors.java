// (13, 1). Write a program to illustrate default and parameterised constructor
// concept

class Test {
   int testInt;
   short testShort;
   long testLong;
   char testChar;
   boolean testBool;
   byte testByte;
   float testFloat;
   double testDouble;
   Test testObject;

   Test() {
      System.out.println("Within default constructor");
      System.out.println("Inititalized Values: ");
      System.out.println("Integer: " + this.testInt);
      System.out.println("Short: " + this.testShort);
      System.out.println("Long: " + this.testLong);
      System.out.println("Char: " + this.testChar);
      System.out.println("Boolean: " + this.testBool);
      System.out.println("Byte: " + this.testByte);
      System.out.println("Float: " + this.testFloat);
      System.out.println("Double: " + this.testDouble);
      System.out.println("Object: " + this.testObject);
   }

   Test(int testInt, short testShort, long testLong, char testChar,
         boolean testBool, byte testByte, float testFloat,
         double testDouble, Test testObject) {
      this.testInt = testInt;
      this.testShort = testShort;
      this.testLong = testLong;
      this.testChar = testChar;
      this.testBool = testBool;
      this.testByte = testByte;
      this.testFloat = testFloat;
      this.testDouble = testDouble;
      this.testObject = testObject;
      System.out.println("Within parameterized constructor");
      System.out.println("Entered Parameters: ");
      System.out.println("testInt: " + this.testInt);
      System.out.println("testShort: " + this.testLong);
      System.out.println("testChar: " + this.testChar);
      System.out.println("testBool: " + this.testBool);
      System.out.println("testByte: " + this.testByte);
      System.out.println("testFloat: " + this.testFloat);
      System.out.println("testDouble: " + this.testDouble);
      System.out.println("testObject: " + this.testObject);
   }
}

public class Constructors {
   public static void main(String[] args) {
      Test testDefault = new Test();
      Test testParameterized = new Test((int) 5, (short) 3, (long) 4, 'a', true,
            (byte) 12, (float) 5.0, (double) 3.5,
            testDefault);

      System.out.println("Objects Initialized: " + testDefault +
            testParameterized);
   }
}
