import java.util.ArrayList;

public class Fruits implements Runnable{
    private ArrayList<String> fruits;
    
    public Fruits(ArrayList<String> fruits) {
        this.fruits = fruits;
    }

    public void run() {
        for (String fruit : this.fruits) {
            try {
                System.out.println(fruit);
                Thread.sleep(2000);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
