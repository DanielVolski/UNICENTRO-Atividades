package e4;

public class ClienteEspecial extends Cliente {
    @Override
       public double calcularDesconto(double valor) {
        return 0.20 * valor;
    }    
}
