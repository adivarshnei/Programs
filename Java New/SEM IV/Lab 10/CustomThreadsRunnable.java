// (34, 4). Write a program to create thread by implementing Runnable interface

class TestThread implements Runnable {
   private int iterations;
   private int iterationsDone;
   private int sleepTime;

   public TestThread(int iterations, int sleepTime) {
      this.iterations = iterations;
      this.iterationsDone = 0;
      this.sleepTime = sleepTime;
   }

   public void run() {
      try {
         while (iterationsDone < iterations) {
            iterationsDone++;
            System.out.println(Thread.currentThread().getName() + " running");
            Thread.sleep(sleepTime);
         }
      } catch (InterruptedException ex) {
         System.out.println(Thread.currentThread().getName() + " interrupted");
      }

      System.out.println("Exit from thread: " +
            Thread.currentThread().getName());
   }
}

public class CustomThreadsRunnable {
   public static void main(String[] args) {
      TestThread one = new TestThread(5, 300);
      Thread threadOne = new Thread(one, "Thread 1");
      TestThread two = new TestThread(6, 200);
      Thread threadTwo = new Thread(two, "Thread 2");
      TestThread three = new TestThread(7, 100);
      Thread threadThree = new Thread(three, "Thread 3");

      System.out.println(threadOne);
      threadOne.start();
      System.out.println(threadTwo);
      threadTwo.start();
      System.out.println(threadThree);
      threadThree.start();

      try {
         Thread.sleep(500);
      } catch (InterruptedException ex) {
         System.out.println("The main thread is interrupted");
      }
   }
}
