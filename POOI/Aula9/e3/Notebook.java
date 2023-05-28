public class Notebook extends Computador {
    private int codigo;
    
    public Notebook() {
        super();
        System.out.println("Notebook()");
        codigo = 12345;
        ligar();
    }
    public void ligar() {
        System.out.println("Codigo: " + codigo);
    }
}
