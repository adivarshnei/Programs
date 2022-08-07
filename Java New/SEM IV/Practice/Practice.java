public class Practice {
   private int hour;
   private int minute;
   private String amPm;

   public Practice(int h, int m, String ap) {
      this.hour = h;
      this.minute = m;
      this.amPm = ap;
   }

   public void advance(int time) {
      this.minute += time;

      while (this.minute >= 60) {
         this.hour++;
         this.minute -= 60;
      }

      while (this.hour > 12) {
         this.hour -= 12;

         if (this.amPm.equals("AM")) {
            this.amPm = "PM";
         } else {
            this.amPm = "AM";
         }
      }

      this.displayTime();
   }

   public void displayTime() {
      System.out.println(String.format("%02d", this.hour) + ":" + 
            String.format("%02d", this.minute) + " " + this.amPm);
   }

   public boolean isWorkTime() {
      if (this.amPm.equals("AM")) {
         if (this.hour >= 9 && this.hour <= 11) {
            return true;
         }
      } else if (this.amPm.equals("PM")) {
         if ((this.hour >= 1 && this.hour <= 5) || this.hour == 12) {
            if (this.hour == 5 && this.minute != 0){
               return false;
            }

            return true;
         }
      }

      return false;
   }

   public static void main(String[] args) {
      System.out.println(new Practice(12, 45, "AM").isWorkTime());
      System.out.println(new Practice(6, 2, "AM").isWorkTime());
      System.out.println(new Practice(8, 59, "AM").isWorkTime());
      System.out.println(new Practice(9, 0, "AM").isWorkTime());
      System.out.println(new Practice(11, 38, "AM").isWorkTime());
      System.out.println(new Practice(12, 53, "PM").isWorkTime());
      System.out.println(new Practice(3, 15, "PM").isWorkTime());
      System.out.println(new Practice(4, 59, "PM").isWorkTime());
      System.out.println(new Practice(5, 0, "PM").isWorkTime());
      System.out.println(new Practice(5, 1, "PM").isWorkTime());
      System.out.println(new Practice(8, 30, "PM").isWorkTime());
      System.out.println(new Practice(11, 59, "PM").isWorkTime());
   }
}
