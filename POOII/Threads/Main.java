public class Main {
    public static void main(String args[]) {
        Thread t1 = new Thread(new Threads1("Thread1"));
        Thread t2 = new Thread(new Threads1("Thread2"));
        Thread t3 = new Thread(new Threads1("Thread3"));

        t1.start();
        t2.start();
        t3.start();
    }
}
