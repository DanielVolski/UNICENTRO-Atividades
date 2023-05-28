package Prova;

public class Vendedor extends Funcionario{
    private double salario;
    //Construtor
    public Vendedor(String nome, double salario) {
        super(nome);
        this.salario = salario;
    }
    //Getters e setters
    public double getSalario() {
        return salario;
    }
    public void setSalario(double salario) {
        this.salario = salario;
    }
}
