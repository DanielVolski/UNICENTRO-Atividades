import java.util.ArrayList;

public class UsaContaBanco {
    public static void main(String args[])
    {
        ArrayList<ContaBanco> contas = new ArrayList<>();
        final int MAX_CONTAS = 4;

        // Instacia e adiciona 4 classes ContaBanco
        for (int i = 0; i < MAX_CONTAS; i++)
            contas.add(new ContaBanco(1000 + i));

        // Mostra quantas instancias existem no array list
        System.out.println("Contas antes do deposito e saque");
        System.out.println(contas.size());

        // Chama o método toString() de cada objeto ContaBanco do array list
        System.out.println(contas);

        contas.get(0).deposito(1000);
        contas.get(1).deposito(1500);
        contas.get(2).deposito(5000);
        contas.get(3).deposito(500);
        System.out.println("Contas depois do deposito");
        System.out.println(contas);

        contas.get(0).saque(500);
        contas.get(1).saque(700);
        contas.get(2).deposito(4000);
        contas.get(3).deposito(50);
        System.out.println("Contas depois do saque");
        System.out.println(contas);

        // Remove a prmieira instancia do array list
        contas.remove(0);

        System.out.println(contas.size());

        System.out.println(contas.get(0));
        System.out.println(contas.get(contas.size() - 1));
    }
}
