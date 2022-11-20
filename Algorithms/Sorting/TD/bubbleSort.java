import java.util.ArrayList;

public class bubbleSort {
    public static final int ARRAY_SIZE = 10;
    public static final int ELEM_LIMIT = 50;
    public static final float TIME_DELAY = 0.005f;

    public static ArrayList<Integer> initArrayValues() {
        ArrayList<Integer> array = new ArrayList<Integer>(this.ARRAY_SIZE);

        for (int i = 0; i < array.size(); i++) {
            array.set(i, (int) (Math.random() * this.ELEM_LIMIT));
        }

        System.out.println(array);

        return null;
    }

    public static void main(String[] args) {
        initArrayValues();
    }
}