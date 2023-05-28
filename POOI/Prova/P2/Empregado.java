public abstract class Empregado implements Pagamento {
    private String endereco;
    private String nome;

    @Override
    public abstract double calculaPagamento();
}
