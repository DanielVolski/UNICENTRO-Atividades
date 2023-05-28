package E1;
public class Percussao implements Instrumento {
    
    @Override
    public void tocar() {
        System.out.println("Tocando instrumento de percussão");
    }

    @Override
    public void nome() {
        System.out.println("Percussão");
    }

    @Override
    public void afinar() {
        System.out.println("Afinando instrumento de percussão");
    }
}
