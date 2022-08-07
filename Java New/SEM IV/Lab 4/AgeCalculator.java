// (18, 6). Write a program to calculate your age

import java.time.LocalDate;
import java.util.Scanner;

class Date {
   private int day;
   private int month;
   private int year;
   private long daysSinceZero;

   final int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
         31 };

   Date(Scanner sc) {
      boolean isLeap = false;

      do {
         System.out.print("Enter the year: ");
         this.year = sc.nextInt();

         if (this.year <= 0) {
            System.out.println("Invalid Year");
         } else {
            isLeap = this.leapChk();
         }
      } while (this.year <= 0);

      do {
         System.out.print("Enter the month: ");
         this.month = sc.nextInt();

         if (this.month <= 0 || this.month > 12) {
            System.out.println("Invalid Month");
         }
      } while (this.month <= 0 || this.month > 12);

      do {
         System.out.print("Enter the day: ");
         this.day = sc.nextInt();

         if (isLeap == true && this.month == 2) {
            if (this.day < 0 || this.day > 29) {
               System.out.println("Invalid Day");
               continue;
            } else {
               break;
            }
         } else if (this.day < 0
               || this.day > this.daysPerMonth[this.month - 1]) {
            System.out.println("Invalid Day");
         }
      } while (this.day < 0 || this.day > this.daysPerMonth[this.month - 1]);

      this.calcDaysSinceZero();
   }

   Date(int day, int month, int year) {
      this.day = day;
      this.month = month;
      this.year = year;
      this.calcDaysSinceZero();
   }

   private void calcDaysSinceZero() {
      this.daysSinceZero = this.day;

      for (int month = 1; month < this.month; month++) {
         this.daysSinceZero += this.daysPerMonth[month - 1];
      }

      this.daysSinceZero += this.year * 365;
      this.daysSinceZero += this.leapCounter();
   }

   private boolean leapChk() {
      boolean isLeap = false;

      if (year % 4 == 0) {
         isLeap = true;

         if (year % 100 == 0) {
            isLeap = false;
         }
         if (year % 400 == 0) {
            isLeap = true;
         }
      }

      return isLeap;
   }

   public int leapCounter() {
      int leapCount = this.year;

      if (this.month <= 2) {
         leapCount--;
      }

      return leapCount / 4 - leapCount / 100 + leapCount / 400;
   }

   public int returnDay() {
      return this.day;
   }

   public int returnMonth() {
      return this.month;
   }

   public int returnYear() {
      return this.year;
   }

   public long returnDaysSinceZero() {
      return this.daysSinceZero;
   }
}

public class AgeCalculator {
   static void ageCalculate(Date dob, Date today) {
      long dayAge = today.returnDaysSinceZero() - dob.returnDaysSinceZero()
            - today.leapCounter() + dob.leapCounter();
      int years = (int) (dayAge / 365);

      System.out.println("Person with a date of birth of " + dob.returnDay()
            + "/" + dob.returnMonth() + "/" + dob.returnYear() + " is " + years
            + " years old ");
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.println("Enter date of birth: ");

      Date dob = new Date(sc);

      Date today = new Date(LocalDate.now().getDayOfMonth(),
            LocalDate.now().getMonthValue(), LocalDate.now().getYear());

      AgeCalculator.ageCalculate(dob, today);

      sc.close();
   }
}
