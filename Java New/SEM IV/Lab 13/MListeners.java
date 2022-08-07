// (41, 2) Write a program to illustrate MouseEvent

import java.awt.*;
import java.awt.event.*;

public class MListeners extends Frame {
   public MListeners() {
      Label mouseButtonLabel = new Label("Mouse Test Area ->", Label.CENTER);
      mouseButtonLabel.setFont(new Font("Consolas", Font.PLAIN, 15));
      mouseButtonLabel.setSize(10, 10);

      Label whichMouseButtonLabel = new Label("", Label.CENTER);
      whichMouseButtonLabel.setFont(new Font("Consolas", Font.BOLD, 15));

      Panel testingArea = new Panel();
      testingArea.setBackground(Color.YELLOW);

      Panel mouseData = new Panel();
      mouseData.add(mouseButtonLabel);
      mouseData.add(whichMouseButtonLabel);

      mouseData.setLayout(new GridLayout(2, 1));

      this.add(mouseData);
      this.add(testingArea);

      this.addWindowListener(new WindowAdapter() {
         @Override
         public void windowClosing(WindowEvent e) {
            dispose();
         }
      });

      testingArea.addMouseListener(new MouseListener() {
         @Override
         public void mouseClicked(MouseEvent e) {
            mouseButtonLabel.setText(
                  "Mouse Clicked at (" + e.getX() + ", " + e.getY() + ")");

            switch (e.getButton()) {
               case 1:
                  whichMouseButtonLabel.setText("Left Click");
                  break;

               case 2:
                  whichMouseButtonLabel.setText("Middle Click");
                  break;

               case 3:
                  whichMouseButtonLabel.setText("Right Click");
                  break;
            }
         }

         @Override
         public void mouseExited(MouseEvent e) {}

         @Override
         public void mouseEntered(MouseEvent e) {}

         @Override
         public void mouseReleased(MouseEvent e) {}

         @Override
         public void mousePressed(MouseEvent e) {}
      });

      this.setSize(400, 200);
      this.setTitle("Mouse Tester");
      this.setLayout(new GridLayout(1, 2));
      this.setLocationRelativeTo(null);
      this.setVisible(true);
   }

   public static void main(String[] args) {
      new MListeners();
   }
}
