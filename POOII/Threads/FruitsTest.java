import java.util.ArrayList;
import java.util.Collections;

public class FruitsTest {
    public static void main(String args[]) {
        ArrayList<String> l1 = new ArrayList<>();
        ArrayList<String> l2 = new ArrayList<>();
        ArrayList<String> l3 = new ArrayList<>();
        Collections.addAll(l1, "Abacate", "Maca", "Banana", "Abacaxi");
        Collections.addAll(l2, "Damasco", "Jabuticaba");
        Collections.addAll(l3, "Ameixa", "Pera", "Manga", "Cereja", "Caqui");
        
        Thread t1 = new Thread(new Fruits(l1));
        Thread t2 = new Thread(new Fruits(l2));
        Thread t3 = new Thread(new Fruits(l3));
        t1.start();
        t2.start();
        t3.start();
    }
}
