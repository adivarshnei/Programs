// (33, 3). Write a program to create a thread by extending Thread class.

class WordPrinter extends Thread {
   private String word;
   private int iterations;
   private int iterationsDone;
   private int sleepTime;

   public WordPrinter(String threadName, String word, int iterations,
         int sleepTime) {
      super(threadName);
      this.word = word;
      this.iterations = iterations;
      this.iterationsDone = 0;
      this.sleepTime = sleepTime;

      System.out.println(this);
      this.start();
   }

   public String getWord() {
      return this.word;
   }

   @Override
   public void run() {
      try {
         while (this.iterationsDone < this.iterations) {
            System.out.println(this.getName() + " returns: " + this.word);
            this.iterationsDone++;
            Thread.sleep(this.sleepTime);
         }
      } catch (InterruptedException ex) {
         System.out.println(this.getName() + " interrupted");
      }

      System.out.println("Exit from thread: " + this.getName());

      this.interrupt();
   }
}

public class CustomThreads {
   public static void main(String[] args) {
      new WordPrinter("Apple Printer", "Apple", 8, 250);
      new WordPrinter("Ball Printer", "Ball", 4, 500);
      new WordPrinter("Cat Printer", "Cat", 2, 1000);
   }
}
