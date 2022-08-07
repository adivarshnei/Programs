// (39, 2) Write a program to illustrate event handling using a choice

import java.awt.*;
import java.awt.event.*;

public class EventListenersChoice extends Frame {
   public enum Colors {
      Red, Blue, Green, Yellow
   }

   Frame frame;

   public EventListenersChoice() {
      frame = new Frame();

      Choice colorChoice = new Choice();

      for (Colors color : Colors.values()) {
         colorChoice.add(color.toString());
      }

      Panel choicePanel = new Panel();
      choicePanel.add(colorChoice);
      choicePanel.setBackground(Color.RED);

      frame.add(choicePanel);

      frame.setSize(400, 200);
      frame.setTitle("Color Changer");
      frame.setLocationRelativeTo(null);
      frame.setLayout(new GridLayout(1, 1));
      frame.setVisible(true);

      frame.addWindowListener(new WindowAdapter() {
         @Override
         public void windowClosing(WindowEvent e) {
            frame.dispose();
         }
      });

      colorChoice.addItemListener(new ItemListener() {
         @Override
         public void itemStateChanged(ItemEvent e) {
            if (colorChoice.getSelectedItem() == Colors.Red.toString()) {
               choicePanel.setBackground(Color.RED);
            } else if (colorChoice.getSelectedItem() == Colors.Green
                  .toString()) {
               choicePanel.setBackground(Color.GREEN);
            } else if (colorChoice.getSelectedItem() == Colors.Yellow
                  .toString()) {
               choicePanel.setBackground(Color.YELLOW);
            } else if (colorChoice.getSelectedItem() == Colors.Blue
                  .toString()) {
               choicePanel.setBackground(Color.BLUE);
            }
         }

      });
   }

   public static void main(String args[]) {
      new EventListenersChoice();
   }
}
