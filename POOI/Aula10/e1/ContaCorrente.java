public class ContaCorrente {
    private double saldo;

    public ContaCorrente(double saldoInicial) {
        saldo = saldoInicial;
    }
    
    public void deposita(double quantia) {
        saldo += quantia;
    }

    public void sacaDinheiro(double quantia) {
        if (saldo >= quantia)
            saldo = saldo - (quantia + taxaOperacao(quantia));
        else
            System.out.println("Saldo Insuficiente!");
    }

    protected double taxaOperacao(double quantia) {
        return quantia * 0.005;
    }

    public double getSaldo() {
        return saldo;
    }
}