public class ValorNegativoException extends Exception {
    private double valor;
    
    public ValorNegativoException (double valor) {
        super();
        this.valor = valor;
    }

    @Override
    public String toString() {
        return "Não é possível realizar o saque negativo de: " + valor;
    }
}
