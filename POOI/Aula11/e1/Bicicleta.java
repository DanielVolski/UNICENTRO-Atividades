package e1;

public class Bicicleta extends Veiculo{
    public Bicicleta() {
        System.out.println("É uma bicicleta");
    }
    @Override
    public void verificar() {
        System.out.println("Verificar bicileta");
    }
    @Override
    public void ajustar() {
        System.out.println("Ajustar bicicleta");
    }
    @Override
    public void limpar() {
        System.out.println("Limpar bicicleta");
    }
}
