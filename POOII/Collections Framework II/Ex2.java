import java.util.*;

public class Ex2 {
    public static void main(String[] args) {
        String[] cores = { "vermelho", "branco", "azul", "verde", "cinza",
                "laranja", "laranja", "cinza", "vermelho" };

        List<String> list = new ArrayList<>(Arrays.asList(cores));
        HashSet<String> hashset = new HashSet<>(list);
        TreeSet<String> treeset = new TreeSet<>(list);

        // Imprime os valores (duplicados tambem) na ordem em que foram definidos
        printCollection(list);
        // Imprime os valores de forma não ordenada e não imprime os valores duplicados
        printCollection(hashset);
        // Imprime os valores em ordem crescente e não imprime os valores duplicados
        printCollection(treeset);
    }
    
    public static void printCollection(Collection<String> col)
    {
        System.out.println("Imprimindo " + col.getClass());
        for (String e: col)
            System.out.println(e);
    }
}
