// (32, 2). Write a Program to Create and Handle Your Own Exception

import java.util.Scanner;

class MarksException extends Exception {
   public MarksException(String string) {
      super(string);
   }
}

class GradeCalculator {
   private int marks[] = { 0, 0, 0, 0, 0 };
   private int totalMarks;

   public void calculateTotalMarks() {
      this.totalMarks = 0;

      for (int m : this.marks) {
         this.totalMarks += m;
      }
   }

   public void setMarks(Scanner sc) throws MarksException {
      for (int i = 0; i < 5; i++) {
         this.marks[i] = sc.nextInt();

         if (this.marks[i] > 100) {
            throw new MarksException("Marks greater than 100 entered");
         }

         if (this.marks[i] < 0) {
            throw new MarksException("Marks lesser than 0 entered");
         }
      }

      this.calculateTotalMarks();
   }

   public char getGrade() {
      char grade = 'A';
      int ll = 450;
      int ul = 500;

      System.out.println("Total Marks: " + this.totalMarks);

      while (true) {
         if (totalMarks < 250) {
            return 'F';
         }

         if (totalMarks > ll && totalMarks <= ul) {
            return grade;
         }

         grade += (char) 1;
         ll -= 50;
         ul -= 50;
      }
   }
}

public class CustomExceptions {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      GradeCalculator gradeCalculator = new GradeCalculator();

      System.out.println("Enter marks in 5 subjects: ");
      try {
         gradeCalculator.setMarks(sc);
         System.out.println("Grade: " + gradeCalculator.getGrade());
      } catch (MarksException ex) {
         ex.printStackTrace();
      } finally {
         sc.close();
      }
   }
}
