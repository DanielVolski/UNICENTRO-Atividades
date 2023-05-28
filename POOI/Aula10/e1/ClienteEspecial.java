public class ClienteEspecial extends ContaCorrente{
    public ClienteEspecial(double saldoInicial) {
        super(saldoInicial);
    }
    @Override
    protected double taxaOperacao(double quantia) {
        return quantia * 0.001;
    }
}
