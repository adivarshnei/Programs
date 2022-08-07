import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Process {
   private int burst;
   private int arrival;
   private int finish;
   private int tat;
   private int wait;
   private int timeLeftToExec;
   // private int timeLeftToArrive;
   private boolean inReadyQueue;

   public static int contextSwitch;

   public Process() {
      this.burst = 0;
      this.arrival = 0;
      this.finish = 0;
      this.tat = 0;
      this.wait = 0;
      this.timeLeftToExec = 0;
      // this.timeLeftToArrive = 0;
      this.inReadyQueue = false;
   }

   /**
    * @param sc Instance of Scanner
    */
   public void initProcess(Scanner sc) {
      System.out.print("Burst: ");
      this.burst = sc.nextInt();

      System.out.print("Arrival: ");
      this.arrival = sc.nextInt();

      this.timeLeftToExec = this.burst;
      // this.timeLeftToArrive = this.arrival;
   }

   public static void initConstants(Scanner sc) {
      System.out.print("Context Switch: ");
      Process.contextSwitch = sc.nextInt();
   }

   public void printProcess() {
      System.out.print(this.burst + "\t");
      System.out.print(this.arrival + "\t");
      System.out.print(this.finish + "\t");
      System.out.print(this.tat + "\t");
      System.out.print(this.wait + "\t");
   }

   public void calcTat() {
      this.tat = this.finish - this.arrival;
   }

   public void calcWait() {
      this.wait = this.tat - this.burst;
   }

   public int getBurst() {
      return this.burst;
   }

   public int getArrival() {
      return this.arrival;
   }

   public boolean getInReadyQueue() {
      return this.inReadyQueue;
   }

   public void setInReadyQueue(boolean newInReadyQueue) {
      this.inReadyQueue = newInReadyQueue;
   }

   public int getTimeLeftToExec() {
      return this.timeLeftToExec;
   }

   public void setTimeLeftToExec(int newTimeLeftToExec) {
      this.timeLeftToExec = newTimeLeftToExec;
   }

   public int getFinish() {
      return this.finish;
   }

   public int getTat() {
      return this.tat;
   }

   public int getWait() {
      return this.wait;
   }

   public void setFinish(int newFinish) {
      this.finish = newFinish;
   }
}


public class SJF {
   private static ArrayList<Process> jobQueue = new ArrayList<Process>();
   private static ArrayList<Process> readyQueue = new ArrayList<Process>();

   public static void sort(ArrayList<Process> processList) {
      for (int i = 0; i < processList.size() - 1; i++) {
         for (int j = 0; j < processList.size() - i - 1; j++) {
            if (processList.get(j).getBurst() > processList.get(j + 1)
                  .getBurst()) {
               Collections.swap(processList, j, j + 1);
            }
         }
      }
   }

   public static void initProcesses(Scanner sc) {
      System.out.print("Enter number of processes: ");

      int noOfProcesses = sc.nextInt();

      for (int i = 0; i < noOfProcesses; i++) {
         System.out.println("Enter data for processes " + (i + 1));

         Process process = new Process();
         process.initProcess(sc);

         jobQueue.add(process);
      }
   }

   public static void printProcesses(ArrayList<Process> processList) {
      System.out.println("Bur\tArr\tFin\tTAT\tWai");

      for (Process process : processList) {
         process.printProcess();
         System.out.println();
      }
   }

   public static void executeProcesses() {
      int time = 0;
      boolean executing = true;
      Process executingProcess = null;

      while (executing) {
         if (!(readyQueue.size() == 0 || executingProcess != null)) {
            for (Process process : readyQueue) {
               if (process.getTimeLeftToExec() > 0) {
                  executingProcess = process;
                  break;
               }
            }
         }

         if (executingProcess != null) {
            executingProcess.setTimeLeftToExec(
                  executingProcess.getTimeLeftToExec() - 1);

            if (executingProcess.getTimeLeftToExec() <= 0) {
               executingProcess.setFinish(time);
               executingProcess = null;
               time += Process.contextSwitch;
            }
         }

         for (Process process : jobQueue) {
            if (process.getArrival() - time <= 0 &&
                  !process.getInReadyQueue()) {
               readyQueue.add(process);
               process.setInReadyQueue(true);
               SJF.sort(readyQueue);
            }
         }

         boolean flag = true;

         for (Process process : jobQueue) {
            if (process.getTimeLeftToExec() > 0) {
               flag = false;
            }
         }

         if (flag) {
            executing = !executing;
         }

         time++;
      }

      for (Process process : jobQueue) {
         process.calcTat();
         process.calcWait();
      }
   }

   public static void printAverages() {
      float avgBurst = 0;
      float avgArrival = 0;
      float avgFinish = 0;
      float avgTat = 0;
      float avgWait = 0;

      for (Process process : jobQueue) {
         avgBurst += process.getBurst();
         avgArrival += process.getArrival();
         avgFinish += process.getFinish();
         avgTat += process.getTat();
         avgWait += process.getWait();
      }

      avgBurst /= (float) jobQueue.size();
      avgArrival /= (float) jobQueue.size();
      avgFinish /= (float) jobQueue.size();
      avgTat /= (float) jobQueue.size();
      avgWait /= (float) jobQueue.size();

      System.out.print(avgBurst + "\t");
      System.out.print(avgArrival + "\t");
      System.out.print(avgFinish + "\t");
      System.out.print(avgTat + "\t");
      System.out.print(avgWait + "\t");
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      SJF.initProcesses(sc);
      Process.initConstants(sc);
      SJF.executeProcesses();
      SJF.printProcesses(jobQueue);
      SJF.printAverages();

      sc.close();
   }
}
