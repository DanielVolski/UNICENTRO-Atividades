package e4;

public class TesteClientes {
    public static void main(String[] args) {
        Cliente c1, c2;
        c1 = new Cliente();
        c2 = new ClienteEspecial();

        System.out.println("Valor de desconto para o cliente em uma compra de R$100,00 : " + c1.calcularDesconto(100));
        System.out.println("Valor de desconto para o cliente especial em uma compra de R$100,00: " + c2.calcularDesconto(100));
    }
}
