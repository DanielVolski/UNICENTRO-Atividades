public class SaldoInsuficienteException extends Exception {
    /** Valor que o usu�rio tentou sacar. */
    private double valor;
     
    /** Saldo da conta. */
    private double saldo;
 
    /** Constructor. */
    public SaldoInsuficienteException(double valor, double saldo) {
      this.valor = valor;
     this.saldo = saldo;
    }
     
   /** @see java.lang.Throwable#toString() */
   @Override
   public String toString() {
      return "O seu saldo (R$ " + saldo + ") � insuficiente para a quantia que "
      + "deseja sacar (+ taxa opera��o): R$ " + valor;
   }
 }
