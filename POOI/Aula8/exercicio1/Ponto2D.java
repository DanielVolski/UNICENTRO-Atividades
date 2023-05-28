public class Ponto2D {
    private double x, y;
    private static int counter;

    

    public Ponto2D() {
        x = 0;
        y = 0;
        ++counter;
    }

    public Ponto2D(double x, double y) {
        this.x = x;
        this.y = y;
        ++counter;
    }

    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }
    public int getCounter() {
        return counter;
    }
}