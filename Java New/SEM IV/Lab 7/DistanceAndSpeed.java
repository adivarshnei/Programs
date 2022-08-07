// (26, 2). Write a program with given interfaces MotorBike and Cycle, then 
// implement in child class TwoWheeler and display distance and speed

import java.util.Scanner;

interface MotorBike {
   public void initBikeSpeed(Scanner sc);

   public void calcBikeDistance();
}

interface Cycle {
   public void initCycleSpeed(Scanner sc);

   public void calcCycleDistance();
}

class TwoWheelerParams {
   public float distance;
   public float speed;
   public float time;

   public void displayParams() {
      System.out.println("Speed: " + String.format("%.2f", this.speed));
      System.out.println("Time Elapsed: " + String.format("%.2f", this.time));
      System.out.println("Distance Travelled: " + String.format("%.2f",
            this.distance));
   }
}

class TwoWheeler implements MotorBike, Cycle {
   private TwoWheelerParams motorBike;
   private TwoWheelerParams cycle;

   TwoWheeler() {
      this.motorBike = new TwoWheelerParams();
      this.cycle = new TwoWheelerParams();
   }

   @Override
   public void initBikeSpeed(Scanner sc) {
      System.out.print("Enter motorbike speed: ");
      this.motorBike.speed = sc.nextFloat();
   }

   @Override
   public void initCycleSpeed(Scanner sc) {
      System.out.print("Enter cycle speed: ");
      this.cycle.speed = sc.nextFloat();
   }

   public void initTime(Scanner sc) {
      System.out.print("Enter time elapsed: ");
      this.motorBike.time = this.cycle.time = sc.nextFloat();
   }

   @Override
   public void calcBikeDistance() {
      this.motorBike.distance = this.motorBike.speed * this.motorBike.time;
   }

   @Override
   public void calcCycleDistance() {
      this.cycle.distance = this.cycle.speed * this.cycle.time;
   }

   public void display() {
      System.out.println("Motorbike: ");
      this.motorBike.displayParams();

      System.out.println("Cycle: ");
      this.cycle.displayParams();
   }
}

public class DistanceAndSpeed {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      TwoWheeler twoWheeler = new TwoWheeler();

      twoWheeler.initBikeSpeed(sc);
      twoWheeler.initCycleSpeed(sc);
      twoWheeler.initTime(sc);

      twoWheeler.calcBikeDistance();
      twoWheeler.calcCycleDistance();

      twoWheeler.display();

      sc.close();
   }
}
