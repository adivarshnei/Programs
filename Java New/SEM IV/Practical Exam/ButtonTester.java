
// Abstract Window Toolkit packages
// Package required for various components
import java.awt.Button;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
// Package required for various events
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

@SuppressWarnings("serial")
class ButtonWindow
  extends Frame {   // Variable used to keep count of button presses
  private static int buttonPressCounter = 0;

  ButtonWindow() {
    // Button to be pressed
    final Button button = new Button("Button");
    button.setSize(100, 50);

    // Label to display number of button presses
    final Label label = new Label("Button Pressed 0 times");

    // Button Panel and adding button Component
    final Panel top = new Panel();
    top.add(button);

    // Label Panel and adding label Component
    final Panel bottom = new Panel();
    bottom.add(label);

    // ActionListener waiting for button press
    button.addActionListener(new ActionListener() {
      // actionPerformed is executed when button is pressed, increments
      // the buttonPressCounter and updates the text of the label
      @Override
      public void actionPerformed(final ActionEvent e) {
        label.setText("Button Pressed " + ++ButtonWindow.buttonPressCounter
                      + " times");
      }
    });

    // WindowListener waiting for window closing
    this.addWindowListener(new WindowAdapter() {
      // windowClosing is executed when the close button on the window is
      // pressed, and disposes of the window
      @Override
      public void windowClosing(final WindowEvent e) {
        dispose();
      }
    });

    // Adding panels to Frame
    this.add(top);
    this.add(bottom);

    // Setting Frame Parameters
    // this.setLayout(new GridLayout(2, 1));
    // this.setSize(500, 200);
    // this.setTitle("Button Tester");
    // this.setVisible(true);
    this.setLayout(new GridLayout(2, 1));
    this.setSize(500, 200);
    this.setTitle("Button Tester");
    this.setVisible(true);
  }
}

// Driver code class
public class ButtonTester {
  public static void main(final String[] args) {
    // Creates new instance of ButtonWindow
    new ButtonWindow();
  }
}
