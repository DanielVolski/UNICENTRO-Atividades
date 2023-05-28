public class Triangulo extends TwoDShape {
    private String estilo;
    //Métodos
    public double area() {
        return (getAltura() * getLargura()) / 2;
    }
    public void mostraEstilo() {
        System.out.println("Triangulo = " + estilo);
    }
    //Getter
    public String getEstilo() {
        return estilo;
    }
    //Setter
    public void setEstilo(String estilo) {
        this.estilo = estilo;
    }  
}
