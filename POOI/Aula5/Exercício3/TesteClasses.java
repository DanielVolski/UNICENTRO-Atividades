package Exercício3;

public class TesteClasses {
    public static void main(String args[]) {
        Universidade universidade = new Universidade();
        Aluno aluno = new Aluno();

        universidade.nome = "Unicentro";
        universidade.cidade = "Guarapuava";
        universidade.estado = "Paraná";
        aluno.nome = "Daniel Flavio";
        aluno.curso = "Ciencia da computação";

        universidade.exibeDados();
        aluno.exibeDados();
    }
}
