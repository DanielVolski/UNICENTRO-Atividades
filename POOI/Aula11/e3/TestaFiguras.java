package e3;

public class TestaFiguras {
    public static void main(String[] args) {
        Figura square, circle;
        square = new Quadrado();
        circle = new Circulo();

        System.out.println("Area de um quadrado de lado 4: " + square.area(4));
        System.out.println("Area de um circulo de raio 8: " + circle.area(8));
    }
}
