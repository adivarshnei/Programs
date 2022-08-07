// 1.
// Write a program which prints the following information about at least 5
// persons:
// NAME MAIL-ID EMPLOYEE-CODE PHONE
// Eg: Umesh umesh@cse p03161 25764728
// Salil salil@cse p03161 25764728
// Each entry should be on a separate line

import java.util.Scanner;

class Employee {
   private String name;
   private String mailId;
   private String empCode;
   private String phoneNum;

   public void getData(Scanner sc) {
      System.out.print("Enter Employee Name: ");
      this.name = sc.nextLine();
      System.out.print("Enter Mail ID: ");
      this.mailId = sc.nextLine();
      System.out.print("Enter Employee Code: ");
      this.empCode = sc.nextLine();
      System.out.print("Enter Phone Number: ");
      this.phoneNum = sc.nextLine();
   }

   public void printData() {
      System.out.println(String.format("%20s%20s%20s%20s", this.name,
            this.mailId, this.empCode, this.phoneNum));
   }
};

public class EmployeeInterface {
   private static final int NO_OF_EMPLOYEES = 5;

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      Employee[] employees = new Employee[NO_OF_EMPLOYEES];

      for (int i = 0; i < employees.length; i++) {
         employees[i] = new Employee();
         employees[i].getData(sc);
      }

      System.out.println(String.format("%20s%20s%20s%20s", "NAME", "MAIL-ID",
            "EMPLOYEE-CODE", "PHONE"));

      for (Employee employee : employees) {
         employee.printData();
      }

      sc.close();
   }
}
