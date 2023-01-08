import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;

public class LinearSearch {
  public static final int ARRAY_LENGTH = 50;
  public static final int ELEM_LIMIT   = 100;
  public static final int NOT_FOUND    = -1;

  public static void printArr(ArrayList<Integer> array) {
    for ( Integer i : array ) {
      System.out.print(i + "\t");
    }
  }

  public static ArrayList<Integer> genRandArr(int len) {
    ArrayList<Integer> array = new ArrayList<Integer>();

    for ( int i = 0; i < len; i++ ) {
      array.add(new Random().nextInt(BinarySearch.ELEM_LIMIT));
    }

    return array;
  }

  public static int
  linearSearch(ArrayList<Integer> array, int query, int loc) {
    if ( loc < 0 ) {
      return LinearSearch.NOT_FOUND;
    } else if ( array.get(loc) == query ) {
      return loc;
    }

    return LinearSearch.linearSearch(array, query, loc - 1);
  }

  public static void main(String[] args) {
    int     len = 0;
    Scanner sc  = new Scanner(System.in);

    do {
      System.out.print("Enter array length: ");
      len = sc.nextInt();
    } while ( len > LinearSearch.ARRAY_LENGTH || len <= 0 );

    ArrayList<Integer> array = genRandArr(len);

    System.out.println("Array: ");
    printArr(array);

    System.out.println("\nEnter element to search for: ");
    int query = sc.nextInt();

    int indexFoundAt = LinearSearch.linearSearch(array, query, len - 1);

    if ( indexFoundAt == -1 ) {
      System.out.println("Element not found");
    } else {
      System.out.println("Element found at index " + indexFoundAt);
    }

    sc.close();
  }
}