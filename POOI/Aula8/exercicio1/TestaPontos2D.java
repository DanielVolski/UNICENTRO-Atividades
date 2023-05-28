public class TestaPontos2D {
    public static void main(String args[]) {
        Ponto2D p1 = new Ponto2D(); //Inicia com os parâmetros padrões
        Ponto2D p2 = new Ponto2D(2, 3); // Usa sobrecarga de construtor

        System.out.printf("P1: %2.1f %2.1f%n", p1.getX(), p1.getY());
        System.out.printf("P2: %2.1f %2.1f%n", p2.getX(), p2.getY());
        System.out.printf("Contador: %d %d%n", p1.getCounter(), p1.getCounter());
    }
}