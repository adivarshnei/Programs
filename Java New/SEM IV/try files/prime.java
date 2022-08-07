import java.util.Scanner;

public class prime {

  public static void main(String[] args) {

    //prompt user
    Scanner obj = new Scanner(System.in);
    int n = 0;

    //for a value greater than
    do {
      System.out.print("Enter the number upto which prime number are to be found: ");
      n = obj.nextInt();
    } while (n <= 1);

    System.out.print("Prime numbers upto " + n + " are ");

    for (int N = 0; N < n; N++) {

      for (int i = 2; i <= N; i++) {
        System.out.println(N + " % " + i);

        if ((N%i) == 0) {
          break;
        }
        else {
          System.out.println(N + " ");
          break;
        }
      }
    }
  }
}