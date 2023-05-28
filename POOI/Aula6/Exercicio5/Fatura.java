public class Fatura {
    private String numero, descricao;
    private int qtdeComprada;
    private double precoUnit;

    public Fatura(String num, String desc, int qtde, double preco) {
        numero = num;
        descricao = desc;
        qtdeComprada = qtde;
        precoUnit = preco;
    }

    public void setNum(String num) {
        numero = num;
    }
    public void setDesc(String desc) {
        descricao = desc;
    }
    public void setQtde(int qtde) {
        qtdeComprada = qtde;
    }
    public void setPreco(double preco) {
        precoUnit = preco;
    }

    public String getNum() {
        return numero;
    }
    public String getDesc() {
        return descricao;
    }
    public int getQtde() {
        return qtdeComprada;
    }
    public double getPreco() {
        return precoUnit;
    }

    public double getQtdeFatura() {
        return qtdeComprada * precoUnit;
    }
}