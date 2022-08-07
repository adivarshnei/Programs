// (36, 2), Write a program to create a file using FileOutputStream class and
//  enter String data into it

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class StringFile {
   public static void main(String[] args) {
      if (args.length < 2) {
         System.out.println("Wrong number of arguments entered.");
         System.out.println("Correct Arguments: <File Name> "
               + " <File Contents Line 1>, <File Contents Line 2> ...");
      } else {
         try {
            FileOutputStream fout = new FileOutputStream(args[0]);

            for (int i = 1; i < args.length; i++) {
               fout.write(args[i].getBytes());
               fout.write('\n');
            }

            fout.close();
         } catch (IOException ex) {
            ex.printStackTrace();
         }

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
