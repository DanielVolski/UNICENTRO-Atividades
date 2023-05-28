public class Exercicio1App {
	public static void main(String[] args) {
		ContaCorrente conta = new ContaCorrente();

		/* Testa a exce��o de valor negativo. */
		try {
			conta.depositar(100);
			conta.depositar(-50);
		} catch (ValorNegativoException e) {
			System.out.println("Exce��o encontrada: " + e);
		}

		/* Testa a exce��o de saldo insuficiente. */ 
		try {
			conta.sacar(70);
			conta.sacar(50);
		} catch (ValorNegativoException | SaldoInsuficienteException e) {
			System.out.println("Exce��o encontrada: " + e);
		}

		System.out.println("Saldo final: R$ " + conta.getSaldo());
	}
}
