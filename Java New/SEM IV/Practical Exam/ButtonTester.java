// Abstract Window Toolkit packages 
// Package required for various components
import java.awt.*;

// Package required for various events
import java.awt.event.*;

class ButtonWindow extends Frame {
    // Variable used to keep count of button presses
    private static int buttonPressCounter = 0;

    ButtonWindow() {
        // Button to be pressed
        Button button = new Button("Button");
        button.setSize(100, 50);

        // Label to display number of button presses
        Label label = new Label("Button Pressed 0 times");

        // Button Panel and adding button Component
        Panel top = new Panel();
        top.add(button);

        // Label Panel and adding label Component
        Panel bottom = new Panel();
        bottom.add(label);

        // ActionListener waiting for button press
        button.addActionListener(new ActionListener() {
            // actionPerformed is executed when button is pressed, increments
            // the buttonPressCounter and updates the text of the label
            @Override
            public void actionPerformed(ActionEvent e) {
                label.setText("Button Pressed "
                        + ++ButtonWindow.buttonPressCounter + " times");
            }
        });

        // WindowListener waiting for window closing
        this.addWindowListener(new WindowAdapter() {
            // windowClosing is executed when the close button on the window is
            // pressed, and disposes of the window
            @Override
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });

        // Adding panels to Frame
        this.add(top);
        this.add(bottom);

        // Setting Frame Parameters
        this.setLayout(new GridLayout(2, 1));
        this.setSize(500, 200);
        this.setTitle("Button Tester");
        this.setVisible(true);
    }
}

// Driver code class
public class ButtonTester {
    public static void main(String[] args) {
        // Creates new instance of ButtonWindow
        new ButtonWindow();
    }
}
