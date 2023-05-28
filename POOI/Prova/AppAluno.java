package Prova;

public class AppAluno {
    public static void main (String args[]) {
        Vendedor vendedor1 = new Vendedor("Daniel Volski", 1500);

        System.out.println("Dados do vendedor1");
        System.out.println("Nome: "+ vendedor1.getNome());
        System.out.println("Salario: "+ vendedor1.getSalario());
    }
}
