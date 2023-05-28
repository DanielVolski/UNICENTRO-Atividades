package e3;

public class Circulo extends Figura {
    @Override
    public double area(double x) {
        return (x*x) * 3.14159;
    }
}