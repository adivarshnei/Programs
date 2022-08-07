// (19, 1). Write a program to illustrate all string and string buffer 
// operations

import java.util.Scanner;

public class Strings {
   static void stringOperations(Scanner sc) {
      System.out.println("String:\n");

      // Character Array to String
      {
         char[] charArray = new char[] { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o',
               'r', 'l', 'd' };
         String stringFromCharArray = new String(charArray);

         System.out.println("Character Array to String Conversion: ");

         System.out.println("Before:");
         System.out.print("(");
         System.out.print(charArray);
         System.out.println(", " + charArray.getClass().getSimpleName() + ")");
         System.out.println("After: ");
         System.out.println("(" + stringFromCharArray + ", "
               + stringFromCharArray.getClass().getSimpleName() + ")");

      }

      System.out.println();

      // String to Character Array
      {
         String string = "Hello World";
         char[] charArrayFromString = string.toCharArray();

         System.out.println("String to Character Array: ");

         System.out.println("Before:");
         System.out.println("(" + string + ", "
               + string.getClass().getSimpleName() + ")");
         System.out.println("After: ");
         System.out.print("(");
         System.out.print(charArrayFromString);
         System.out.println(", " +
               charArrayFromString.getClass().getSimpleName() + ")");
      }

      System.out.println();

      // String Methods
      {
         System.out.println("String methods: ");

         String string1 = "Hello";
         String string2 = "World";
         String string3 = "    Hello    ";

         System.out.println("Length of " + string1 + " = " + string1.length());
         System.out.println("Concatenation of " + string1 + ", " + string2
               + ", 1, 2 and 3: "
               + string1.concat(string2).concat("1").concat("2").concat("3"));

         int position = 2;

         System.out.println("Character at position " + position + " of "
               + string1 + ": " + string1.charAt(position));

         System.out.println("Are strings " + string1 + " and " + string2
               + " identical?: " + string1.equals(string2));
         System.out.println("Are strings " + string1 + " and " + "Hello"
               + " identical?: " + string1.equals("Hello"));
         System.out.println("Are strings " + string1 + " and " + "hello"
               + " identical?: " + string1.equals("hello"));

         System.out.println("Are strings " + string1 + " and " + string2
               + " identical (case insensitive)?: "
               + string1.equalsIgnoreCase(string2));
         System.out.println("Are strings " + string1 + " and " + "Hello"
               + " identical (case insensitive)?: "
               + string1.equalsIgnoreCase("Hello"));
         System.out.println("Are strings " + string1 + " and " + "hello"
               + " identical (case insensitive)?: "
               + string1.equalsIgnoreCase("hello"));

         System.out.println("Does " + string1 + " start with hel?: "
               + string1.startsWith("hel"));
         System.out.println("Does " + string1 + " start with Hel?: "
               + string1.startsWith("Hel"));

         System.out.println("Does " + string1 + " end with llo?: "
               + string1.endsWith("llo"));
         System.out.println("Does " + string1 + " end with Llo?: "
               + string1.endsWith("Llo"));

         System.out.println("Lexicographical comparison of " + string1
               + " and Hello: " + string1.compareTo("Hello"));
         System.out.println("Lexicographical comparison of " + string1
               + " and hello: " + string1.compareTo("hello"));

         System.out.println("First occurance of l in " + string1 + ": "
               + string1.indexOf("l"));
         System.out.println("Last occurance of l in " + string1 + ": "
               + string1.lastIndexOf("l"));

         System.out.println("Substring of " + string1 + " starting from "
               + position + ": " + string1.substring(position));
         System.out.println("Substring of " + string1 + " starting from "
               + position + " and ending at " + (position + 2) + ": "
               + string1.substring(position, position + 2));

         System.out.println("Lowercase form of " + string1 + ": " +
               string1.toLowerCase());
         System.out.println("Uppercase form of " + string1 + ": " +
               string1.toUpperCase());

         System.out.println(string1 + " with e replaced by a: " +
               string1.replace("e", "a"));

         System.out.println(string3 + " with additional whitespace removed: "
               + string3.trim());

         char[] charArray = { 'a', 'e', 'i', 'o', 'u' };

         System.out.print("String representation of ");
         System.out.print(charArray);
         System.out.println(": " + String.valueOf(charArray));
      }
   }

   static void stringBufferOperations(Scanner sc) {
      System.out.println("\nStringBuffer:\n");

      int size = 10;
      String string = "Hello";

      // StringBuffer Constructors
      {
         System.out.println("StringBuffer Constructors: ");

         StringBuffer stringBuffer = new StringBuffer();
         StringBuffer stringBufferFromSize = new StringBuffer(size);
         StringBuffer stringBufferFromString = new StringBuffer(string);

         System.out.println("Base Constructor StringBuffer: (" + stringBuffer
               + ", " + stringBuffer.getClass().getSimpleName() + ")");
         System.out.println("Size Constructor StringBuffer: ("
               + stringBufferFromSize + ", "
               + stringBufferFromSize.getClass().getSimpleName() + ")");
         System.out.println("String Constructor StringBuffer: (" +
               stringBufferFromString + ", "
               + stringBufferFromString.getClass().getSimpleName() + ")");
      }

      System.out.println();

      // StringBuffer Methods
      {
         System.out.println("StringBuffer Methods:");

         StringBuffer stringBuffer = new StringBuffer(string);
         System.out.println("Base String: " + stringBuffer);

         System.out.print("Appending 123 to " + stringBuffer + ": ");
         System.out.println(stringBuffer.append(123));

         System.out.print("Appending  World to " + stringBuffer + ": ");
         System.out.println(stringBuffer.append(" World"));

         System.out.print("Inserting app at position 5 to "
               + stringBuffer + ": ");
         System.out.println(stringBuffer.insert(5, "app"));

         System.out.print("Deleting characters in between position 2 and 10 "
               + stringBuffer + ": ");
         System.out.println(stringBuffer.delete(2, 10));

         System.out.print("Replacing characters between positions 2 and 6 by "
               + "Globe in " + stringBuffer + ": ");
         System.out.println(stringBuffer.replace(2, 6, "Globe"));

         System.out.println("Substring of " + stringBuffer + " starting at"
               + " position 4: " + stringBuffer.substring(4));

         System.out.print("Reverse of " + stringBuffer + "is: ");
         System.out.println(stringBuffer.reverse());

         System.out.println("Length of " + stringBuffer + " is: " +
               stringBuffer.length());

         stringBuffer.setLength(20);
         System.out.println("New length of " + stringBuffer + " is: "
               + stringBuffer.length());

         System.out.println("Capacity of " + stringBuffer + " is: "
               + stringBuffer.capacity());

         System.out.println("Character at position 3 of " + stringBuffer + ": "
               + stringBuffer.charAt(3));

         System.out.print("Setting character at position 3 of " + stringBuffer
               + " to m: ");
         stringBuffer.setCharAt(3, 'm');
         System.out.println(stringBuffer);
      }
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      Strings.stringOperations(sc);
      System.out.println();
      Strings.stringBufferOperations(sc);

      sc.close();
   }
}
