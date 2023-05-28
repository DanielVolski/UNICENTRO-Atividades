package E1;
public class Corda implements Instrumento {

    @Override
    public void tocar() {
        System.out.println("Tocando instrumento de corda");
    }

    @Override
    public void nome() {
        System.out.println("Corda");
    }

    @Override
    public void afinar() {
        System.out.println("Afinando instrumento de corda");
    }
    
}
