// (29, 5). Write a program to implement all functions of Iterator interface

import java.util.Iterator;
import java.util.Scanner;

class Node {
   private Integer value;
   private Node next;
   private Node prev;

   Node(Integer value, Node next, Node prev) {
      this.value = value;
      this.next = next;
      this.prev = prev;
   }

   public void setNext(Node next) {
      this.next = next;
   }

   public void setPrev(Node prev) {
      this.prev = prev;
   }

   public Integer getValue() {
      return this.value;
   }

   public Node getNext() {
      return this.next;
   }

   public Node getPrev() {
      return this.prev;
   }
}

class Stack implements Iterable<Integer> {
   private Node bottom;
   private Node top;

   Stack(Integer[] integers) {
      for (Integer integer : integers) {
         this.add(integer);
      }
   }

   public void add(Integer value) {
      Node node = new Node(value, null, null);

      if (this.bottom == null) {
         this.bottom = node;
         this.top = node;
      } else {
         this.top.setNext(node);
         Node temp = this.top;
         this.top = node;
         this.top.setPrev(temp);
      }
   }

   public Node getHead() {
      return this.bottom;
   }

   public Node getTail() {
      return this.top;
   }

   public void emptyStack() {
      this.bottom = null;
      this.top = null;
   }

   @Override
   public Iterator<Integer> iterator() {
      return new StackIterator(this);
   }
}

class StackIterator implements Iterator<Integer> {
   private Node current;
   private Stack stack;

   StackIterator(Stack stack) {
      this.stack = stack;
      this.current = this.stack.getHead();
   }

   @Override
   public boolean hasNext() {
      return (current != null);
   }

   @Override
   public Integer next() {
      Integer value = this.current.getValue();
      this.current = this.current.getNext();
      return value;
   }

   @Override
   public void remove() {
      Node temp = this.current;

      if (temp == null) {
         System.out.println("No elements in stack.");
         return;
      }

      while (true) {
         if (temp.getNext() != null) {
            temp = temp.getNext();
         } else {
            break;
         }
      }

      Integer value = temp.getValue();

      if (temp.getPrev() != null) {
         temp = temp.getPrev();
         temp.setNext(null);
      } else {
         this.stack.emptyStack();
      }
      System.out.println(value + " popped from stack.");
   }
}

public class IteratorImplementation {
   public static void push(Stack integers, Scanner sc) {
      System.out.print("Enter an integer: ");
      integers.add(sc.nextInt());
   }

   public static void pop(Stack integers) {
      integers.iterator().remove();
   }

   public static void displayStack(Stack integers) {
      System.out.print("Stack: ");

      for (Integer integer : integers) {
         System.out.print(integer + " ");
      }

      System.out.println();
   }

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int choice;

      Integer[] integerArray = { 0, 1, 2, 3, 4 };

      Stack integers = new Stack(integerArray);

      IteratorImplementation.displayStack(integers);

      do {
         System.out.println("1. Push");
         System.out.println("2. Pop");
         System.out.println("3. Display");
         System.out.println("4. Exit");
         System.out.print("Enter Choice: ");
         choice = sc.nextInt();

         switch (choice) {
            case 1:
               IteratorImplementation.push(integers, sc);
               IteratorImplementation.displayStack(integers);
               break;

            case 2:
               IteratorImplementation.pop(integers);
               IteratorImplementation.displayStack(integers);
               break;

            case 3:
               IteratorImplementation.displayStack(integers);
               break;

            case 4:
               break;

            default:
               System.out.println("Wrong Choice");
               break;
         }
      } while (choice != 4);

      sc.close();
   }
}