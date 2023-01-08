import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;

public class BinarySearch {
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
  binarySearch(ArrayList<Integer> array, int query, int low, int high) {
    if ( low > high ) {
      return BinarySearch.NOT_FOUND;
    }

    int mid = (low + high) / 2;

    if ( array.get(mid) == query ) {
      return mid;
    } else if ( array.get(mid) < query ) {
      return BinarySearch.binarySearch(array, query, mid + 1, high);
    } else {
      return BinarySearch.binarySearch(array, query, low, mid - 1);
    }
  }

  public static void main(String[] args) {
    int     len = 0;
    Scanner sc  = new Scanner(System.in);

    do {
      System.out.print("Enter array length: ");
      len = sc.nextInt();
    } while ( len > BinarySearch.ARRAY_LENGTH || len <= 0 );

    ArrayList<Integer> array = BinarySearch.genRandArr(len);

    System.out.println("Array: ");
    printArr(array);

    Collections.sort(array);

    System.out.println("\nSorted Array: ");
    printArr(array);

    System.out.println("\nEnter element to search for: ");
    int query = sc.nextInt();

    int indexFoundAt = BinarySearch.binarySearch(array, query, 0, len - 1);

    if ( indexFoundAt == -1 ) {
      System.out.println("Element not found");
    } else {
      System.out.println("Element found at index " + indexFoundAt);
    }

    sc.close();
  }
}