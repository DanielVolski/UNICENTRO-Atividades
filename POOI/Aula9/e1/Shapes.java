public class Shapes {
    public static void main(String[] args) {
        Retangulo r1 = new Retangulo();
        Retangulo r2 = new Retangulo();
        Triangulo t1 = new Triangulo();
        Triangulo t2 = new Triangulo();

        r1.setAltura(4);
        r1.setLargura(4);

        r2.setAltura(2);
        r2.setLargura(4);

        t1.setAltura(5);
        t1.setLargura(10);
        t1.setEstilo("cheio");

        t2.setAltura(6);
        t2.setLargura(12);
        t2.setEstilo("contorno");

        System.out.println("Info r1");
        System.out.println("Altura = " + r1.getAltura());
        System.out.println("Largura = " + r1.getLargura());
        System.out.println("Area = " + r1.area());
        System.out.printf("E quadrado?%b%n", r1.checaQuadrado());
        System.out.println();
        System.out.println("Info r2");
        System.out.println("Altura = " + r2.getAltura());
        System.out.println("Largura = " + r2.getLargura());
        System.out.println("Area = " + r2.area());
        System.out.printf("E quadrado?%b%n", r1.checaQuadrado());
        System.out.println();
        System.out.println("Info para t1: ");
        t1.mostraEstilo();
        t1.mostraDim();
        System.out.println("Area = " + t1.area());
        System.out.println();
        System.out.println("Info para t2: ");
        t2.mostraEstilo();
        t2.mostraDim();
        System.out.println("Area = " + t2.area());
        

        
    }
}
