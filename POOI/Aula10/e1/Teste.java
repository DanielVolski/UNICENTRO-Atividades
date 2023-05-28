public class Teste {
    public static void main(String args[]) {
        ContaCorrente cliente1 = new ContaCorrente(1000);
        ContaCorrente cliente2 = new ClienteEspecial(1000);

        System.out.println("Cliente 1");
        System.out.println("Saldo = " + cliente1.getSaldo());
        cliente1.sacaDinheiro(500);
        System.out.println("Saldo = " + cliente1.getSaldo());
        cliente1.deposita(600);
        System.out.println("Saldo = " + cliente2.getSaldo());
        System.out.println();
        System.out.println("Cliente 2");
        System.out.println("Saldo = " + cliente2.getSaldo());
        cliente2.sacaDinheiro(500);
        System.out.println("Saldo = " + cliente2.getSaldo());
        cliente2.deposita(600);
        System.out.println("Saldo = " + cliente2.getSaldo());
    }
}
