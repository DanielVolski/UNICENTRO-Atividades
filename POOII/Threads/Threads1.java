public class Threads1 implements Runnable {
    private String name;

    public Threads1(String name) {
        this.name = name;
    }

    public void run() {
        System.out.println(this.name + " executing.");
        try {
            Thread.sleep(2000);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        System.out.println(this.name + " finishing.");
    }
}