// (37, 3) Open a file using FileInputStream, read its content and display on
// screen.

import java.io.FileInputStream;
import java.io.IOException;

public class FileDisplay {
   public static void main(String[] args) {
      if (args.length != 1) {
         System.out.println("Wrong number of arguments entered");
         System.out.println("Correct Argument: <File Name>");
      } else {
         try {
            FileInputStream fin = new FileInputStream(args[0]);
            byte arr[] = new byte[100];
            fin.read(arr);
            System.out.println(new String(arr));

            fin.close();
         } catch (IOException ex) {
            ex.printStackTrace();
         }
      }
   }
}
