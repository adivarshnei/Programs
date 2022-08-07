// (38, 1) Write a program to illustrate event handling using a button

import java.awt.*;
import java.awt.event.*;

public class EventListenersButton extends Frame {
   public static final int FIELD_WIDTH = 10;

   public enum State {
      ERROR, NORMAL
   }

   public static State buttonState = State.NORMAL;

   public EventListenersButton() {
      TextField operand1Field = new TextField(FIELD_WIDTH);
      TextField operand2Field = new TextField(FIELD_WIDTH);
      TextField resultField = new TextField(FIELD_WIDTH);
      resultField.setEditable(false);

      Label equalsLabel = new Label("=");
      Label operatorLabel = new Label(" ");

      Button calculateButton = new Button("Calculate");

      CheckboxGroup operatorChoice = new CheckboxGroup();
      Checkbox add = new Checkbox("+", operatorChoice, true);
      Checkbox subtract = new Checkbox("-", operatorChoice, false);
      Checkbox multiply = new Checkbox("x", operatorChoice, false);
      Checkbox divide = new Checkbox("/", operatorChoice, false);

      Panel top = new Panel();
      top.add(operand1Field);
      top.add(operatorLabel);
      top.add(operand2Field);
      top.add(equalsLabel);
      top.add(resultField);

      Panel middle = new Panel();
      middle.add(add);
      middle.add(subtract);
      middle.add(multiply);
      middle.add(divide);

      Panel bottom = new Panel();
      bottom.add(calculateButton);

      this.add(top);
      this.add(middle);
      this.add(bottom);

      this.setSize(400, 200);
      this.setTitle("Simple Calculator");
      this.setLocationRelativeTo(null);
      this.setLayout(new GridLayout(3, 1));
      this.setVisible(true);

      this.addWindowListener(new WindowAdapter() {
         @Override
         public void windowClosing(WindowEvent e) {
            dispose();
         }
      });

      calculateButton.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            try {
               if (buttonState == State.NORMAL) {
                  float op1 = Float.parseFloat(operand1Field.getText());
                  float op2 = Float.parseFloat(operand2Field.getText());
                  Float result = 0.0f;

                  if (operatorChoice.getSelectedCheckbox() == add) {
                     operatorLabel.setText("+");
                     result = op1 + op2;
                  } else if (operatorChoice.getSelectedCheckbox() == subtract) {
                     operatorLabel.setText("-");
                     result = op1 - op2;
                  } else if (operatorChoice.getSelectedCheckbox() == multiply) {
                     operatorLabel.setText("x");
                     result = op1 * op2;
                  } else if (operatorChoice.getSelectedCheckbox() == divide) {
                     operatorLabel.setText("/");
                     result = op1 / op2;
                  }

                  resultField.setText(result.toString());
               } else if (buttonState == State.ERROR) {
                  operand1Field.setEditable(true);
                  operand2Field.setEditable(true);
                  operand1Field.setText("");
                  operand2Field.setText("");
                  resultField.setText("");

                  calculateButton.setLabel("Submit");

                  buttonState = State.NORMAL;
               }
            } catch (NumberFormatException ex) {
               operand1Field.setText("ERR");
               operand2Field.setText("ERR");
               resultField.setText("ERR");
               operatorLabel.setText(" ");

               operand1Field.setEditable(false);
               operand2Field.setEditable(false);

               calculateButton.setLabel("RESET");

               buttonState = State.ERROR;
            }
         }
      });
   }

   public static void main(String[] args) {
      new EventListenersButton();
   }
}

