public class PagamentoApp {
    public static void main(String[] args) {
        Empregado empregado1 = new EmpregadoAssalariado(500);
        Empregado empregado2 = new EmpregadoHorista(10, 100);

        Empregado empregados[] = {empregado1, empregado2};

        for(int i = 0; i < empregados.length; i++) {
            System.out.println("Pagamento do empregado: " + empregados[i].calculaPagamento());
        }
    }
}
