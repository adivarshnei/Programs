// (40, 1) Write a program to illustrate KeyEvent

import java.awt.Font;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

@SuppressWarnings("serial")
public class KListeners extends Frame {
    private int keyCount = 0;

    public KListeners() {
        final Label key = new Label("", Label.CENTER);
        final Label keyCounter = new Label(
            "Total Key Presses Detected: " + Integer.toString(keyCount),
            Label.CENTER);

        key.setFont(new Font("Consolas", Font.BOLD, 30));
        keyCounter.setFont(new Font("Consolas", Font.PLAIN, 16));

        final Panel keyboardTop = new Panel();

        final Label dummyLabel = new Label("Key Press Detected", Label.CENTER);
        dummyLabel.setFont(new Font("Consolas", Font.PLAIN, 16));

        keyboardTop.add(dummyLabel);
        keyboardTop.add(key);
        keyboardTop.setLayout(new GridLayout(1, 2));

        this.add(keyboardTop);
        this.add(keyCounter);

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(final WindowEvent e) {
                dispose();
            }
        });

        this.addKeyListener(new KeyListener() {
            @Override
            public void keyPressed(final KeyEvent e) {
                key.setText(KeyEvent.getKeyText(e.getKeyCode()));
                keyCount += 1;
                keyCounter.setText("Total Key Presses Detected: " +
                                   Integer.toString(keyCount));
            }

            @Override
            public void keyTyped(final KeyEvent e) { }

            @Override
            public void keyReleased(final KeyEvent e) { }
        });

        this.setSize(600, 200);
        this.setTitle("Keyboard Tester");
        this.setLayout(new GridLayout(2, 1));
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    public int getKeyCount() {
        return keyCount;
    }

    public void setKeyCount(int keyCount) {
        this.keyCount = keyCount;
    }

    public static void main(final String[] args) {
        new KListeners();
    }
}
