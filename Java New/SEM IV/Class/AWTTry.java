import java.awt.*;

public class AWTTry extends Frame{
   AWTTry() {
      Button b = new Button("click");
      b.setBounds(10, 20, 100, 200);
      this.add(b);

      this.setSize(300, 300);
      this.setTitle("Hi");
      this.setLayout(null);
      this.setVisible(true);
   }

   public static void main(String[] args) {
      AWTTry a = new AWTTry();
      System.out.print(1);
   }
}
