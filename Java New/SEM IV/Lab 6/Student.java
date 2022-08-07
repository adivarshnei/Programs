// (20, 1). Write a program to maintain the student record containing roll
// number, name, marks1, marks2, marks3 as data members and getdata(), display()
// and setdata() as member functions

import java.util.Scanner;

class Record {
   private int rollNumber;
   private String name;
   private int marks1;
   private int marks2;
   private int marks3;

   public void setData(int rollNumber, String name, int marks1, int marks2,
         int marks3) {
      this.rollNumber = rollNumber;
      this.name = name;
      this.marks1 = marks1;
      this.marks2 = marks2;
      this.marks3 = marks3;
   }

   public int getRollNumber() {
      return this.rollNumber;
   }

   public String getName() {
      return this.name;
   }

   public int getMarks1() {
      return this.marks1;
   }

   public int getMarks2() {
      return this.marks2;
   }

   public int getMarks3() {
      return this.marks3;
   }

   public void display() {
      System.out.println("Data Display Using Member Function");
      System.out.println("Roll Number: " + this.rollNumber);
      System.out.println("Name: " + this.name);
      System.out.println("Marks in Subject 1: " + this.marks1);
      System.out.println("Marks in Subject 2: " + this.marks2);
      System.out.println("Marks in Subject 3: " + this.marks3);
   }
}

public class Student {
   static void displayData(Record record) {
      System.out.println("Data Display Using Getters");
      System.out.println("Roll Number: " + record.getRollNumber());
      System.out.println("Name: " + record.getName());
      System.out.println("Marks in Subject 1: " + record.getMarks1());
      System.out.println("Marks in Subject 2: " + record.getMarks2());
      System.out.println("Marks in Subject 3: " + record.getMarks3());

   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.println("Data Entry");
      System.out.print("Enter Roll Number: ");
      int rollNumber = sc.nextInt();
      sc.nextLine();
      System.out.print("Enter Name: ");
      String name = sc.nextLine();
      System.out.print("Enter Marks in Subject 1: ");
      int marks1 = sc.nextInt();
      System.out.print("Enter Marks in Subject 2: ");
      int marks2 = sc.nextInt();
      System.out.print("Enter Marks in Subject 3: ");
      int marks3 = sc.nextInt();

      Record record = new Record();

      record.setData(rollNumber, name, marks1, marks2, marks3);

      System.out.println();
      record.display();
      System.out.println();
      Student.displayData(record);

      sc.close();
   }
}