package E1;
public class SoproMadeira extends Sopro {
    @Override
    public void nome() {
        System.out.println("Sopro madeira");
    }

    @Override
    public void afinar() {
        System.out.println("Afinando instrumento de sopro madeira");
    }
}
