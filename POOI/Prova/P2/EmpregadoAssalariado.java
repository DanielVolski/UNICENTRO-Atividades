public class EmpregadoAssalariado extends Empregado {
    private double salarioMensal;

    EmpregadoAssalariado(double salarioMensal) {
        this.salarioMensal = salarioMensal;
    }

    @Override
    public double calculaPagamento() {
        return salarioMensal;
    }
}
