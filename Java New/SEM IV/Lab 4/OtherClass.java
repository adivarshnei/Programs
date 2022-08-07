// (14, 2). Write a program to create 3 objects of a class and use getters and 
// setters to access data variables and methods.

import java.util.Scanner;

class PersonInformation {
   String name;
   int age;
   int height;

   void getData(Scanner sc) {
      System.out.print("Enter name: ");
      this.name = sc.nextLine();
      System.out.print("Enter age: ");
      this.age = sc.nextInt();
      System.out.print("Enter height: ");
      this.height = sc.nextInt();
   }

   void showData() {
      System.out.println("Name of Person = " + this.name);
      System.out.println("Age of Person = " + this.age);
      System.out.println("Height of Person = " + this.height);
   }
}

class Test2 {}

public class OtherClass {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      PersonInformation[] persons;
      persons = new PersonInformation[3];

      for (int i = 0; i < 3; i++) {
         persons[i] = new PersonInformation();
      }

      for (PersonInformation person : persons) {
         person.getData(sc);

         sc.nextLine();
      }

      System.out.println();
      System.out.println("Entered Data: ");

      for (PersonInformation person : persons) {
         person.showData();
      }

      sc.close();
   }
}
