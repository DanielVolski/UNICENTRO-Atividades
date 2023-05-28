public class TwoDShape {
    private double largura;
    private double altura;

    public void mostraDim() {
        System.out.printf("Largura = %s%nAltura = %s%n", largura, altura);
    }
    //Acessadires
    public double getLargura() {
        return largura;
    }
    public double getAltura() {
        return altura;
    }
    //Modificadores
    public void setLargura(double largura) {
        this.largura = largura;
    }
    public void setAltura(double altura) {
        this.altura = altura;
    }
}
