public class usaFatura {
    public static void main (String args []) {
        Fatura fatura1 = new Fatura("123", "Teste", 20, 200);

        System.out.println(fatura1.getNum());
        System.out.println(fatura1.getDesc());
        System.out.println(fatura1.getQtde());
        System.out.println(fatura1.getPreco());
        System.out.println(fatura1.getQtdeFatura());
    }
}
