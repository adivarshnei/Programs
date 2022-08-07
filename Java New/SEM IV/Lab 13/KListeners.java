// (40, 1) Write a program to illustrate KeyEvent

import java.awt.*;
import java.awt.event.*;

public class KListeners extends Frame {
   private int keyCount = 0;

   public KListeners() {
      Label key = new Label("", Label.CENTER);
      Label keyCounter = new Label(
            "Total Key Presses Detected: " + Integer.toString(keyCount),
            Label.CENTER);

      key.setFont(new Font("Consolas", Font.BOLD, 30));
      keyCounter.setFont(new Font("Consolas", Font.PLAIN, 16));

      Panel keyboardTop = new Panel();

      Label dummyLabel = new Label("Key Press Detected", Label.CENTER);
      dummyLabel.setFont(new Font("Consolas", Font.PLAIN, 16));

      keyboardTop.add(dummyLabel);
      keyboardTop.add(key);
      keyboardTop.setLayout(new GridLayout(1, 2));

      this.add(keyboardTop);
      this.add(keyCounter);

      this.addWindowListener(new WindowAdapter() {
         @Override
         public void windowClosing(WindowEvent e) {
            dispose();
         }
      });

      this.addKeyListener(new KeyListener() {
         @Override
         public void keyPressed(KeyEvent e) {
            key.setText(KeyEvent.getKeyText(e.getKeyCode()));
            keyCount += 1;
            keyCounter.setText(
                  "Total Key Presses Detected: " + Integer.toString(keyCount));
         }

         @Override
         public void keyTyped(KeyEvent e) {}

         @Override
         public void keyReleased(KeyEvent e) {}
      });

      this.setSize(600, 200);
      this.setTitle("Keyboard Tester");
      this.setLayout(new GridLayout(2, 1));
      this.setLocationRelativeTo(null);
      this.setVisible(true);
   }

   public static void main(String[] args) {
      new KListeners();
   }
}
