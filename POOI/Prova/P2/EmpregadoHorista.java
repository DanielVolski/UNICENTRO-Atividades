public class EmpregadoHorista extends Empregado {
    private int horasTrabalhadas;
    private double salarioHora;

    EmpregadoHorista(double salarioHora, int horasTrabalhadas) {
        this.salarioHora = salarioHora;
        this.horasTrabalhadas = horasTrabalhadas;
    }

    @Override
    public double calculaPagamento() {
        return horasTrabalhadas * salarioHora;
    }
}
