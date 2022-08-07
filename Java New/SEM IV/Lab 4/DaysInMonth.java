// (16, 4). Write a program to find the number of days in a month

import java.util.Scanner;

public class DaysInMonth {
   static class DayAndName {
      int days;
      String name;

      DayAndName(int days, String name) {
         this.days = days;
         this.name = name;
      }

      int returnDays() {
         return this.days;
      }

      String returnName() {
         return this.name;
      }
   }

   static final DayAndName dayAndMonthArray[] = {
         new DayAndName(31, "January"),
         new DayAndName(28, "February"),
         new DayAndName(31, "March"),
         new DayAndName(30, "April"),
         new DayAndName(31, "May"),
         new DayAndName(30, "June"),
         new DayAndName(31, "July"),
         new DayAndName(31, "August"),
         new DayAndName(30, "September"),
         new DayAndName(31, "October"),
         new DayAndName(30, "November"),
         new DayAndName(31, "December")
   };

   static void numberOfDays(int month) {
      System.out.print(dayAndMonthArray[month - 1].returnName() + " has "
            + dayAndMonthArray[month - 1].returnDays() + " days");
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter month number: ");
      int month = sc.nextInt();

      DaysInMonth.numberOfDays(month);

      sc.close();
   }
}
