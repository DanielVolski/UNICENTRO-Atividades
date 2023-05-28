package E1;
public class Sopro implements Instrumento {
    
    @Override
    public void tocar() {
        System.out.println("Tocando instrumento de sopro");
    }

    @Override
    public void nome() {
        System.out.println("Sopro");
    }

    @Override
    public void afinar() {
        System.out.println("Afinando instrumento de sopro");
    }
}
