// (21, 2). Write a program to increment the employee salaries on the basis of
// their designation (Manager - 5000, General Manager - 10000, CEO - 20000,
// Worker - 2000). Use employee name, id, designation, salary as data member
//  and inc_sal as member function.

import java.util.Scanner;

enum Designation {
   MANAGER("Manager", 5000), GENERAL_MANAGER("General Manager",
         10000), CEO("CEO", 20000), WORKER("Worker", 2000);

   private final String designationName;
   private final int incrementAmount;

   Designation(String designationName, int incrementAmount) {
      this.designationName = designationName;
      this.incrementAmount = incrementAmount;
   }

   public String returnDesignationName() {
      return this.designationName;
   }

   public int returnIncrementAmount() {
      return this.incrementAmount;
   }
}

class Employee {
   private String name;
   private int id;
   private Designation designation;
   private int salary;

   public void setData(String name, int id, Designation designation,
         int salary) {
      this.name = name;
      this.id = id;
      this.designation = designation;
      this.salary = salary;
   }

   public void inc_sal() {
      this.salary += this.designation.returnIncrementAmount();
   }

   public void display() {
      System.out.println("Employee Display: ");
      System.out.println("Name: " + this.name);
      System.out.println("ID: " + this.id);
      System.out.println("Designation: "
            + this.designation.returnDesignationName());
      System.out.println("Salary: " + this.salary);
   }
}

public class Salaries {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter name of employee: ");
      String name = sc.nextLine();
      System.out.print("Enter id of employee: ");
      int id = sc.nextInt();
      Designation designation;

      do {
         System.out.println("1. Manager");
         System.out.println("2. General Manager");
         System.out.println("3. CEO");
         System.out.println("4. Worker");
         System.out.print("Choose designation of employee: ");

         switch (sc.nextInt()) {
            case 1:
               designation = Designation.MANAGER;
               break;

            case 2:
               designation = Designation.GENERAL_MANAGER;
               break;

            case 3:
               designation = Designation.CEO;
               break;

            case 4:
               designation = Designation.WORKER;
               break;

            default:
               continue;
         }

         break;
      } while (true);

      System.out.print("Enter salary of employee: ");
      int salary = sc.nextInt();

      Employee employee = new Employee();

      System.out.println();

      employee.setData(name, id, designation, salary);
      employee.display();

      System.out.println("\nAfter Increment\n");

      employee.inc_sal();
      employee.display();

      sc.close();
   }
}
