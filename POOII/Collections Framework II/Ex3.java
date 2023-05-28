import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        String[] cores = { "preto", "amarelo", "verde", "azul", "branco" };
        List<String> list1 = new LinkedList<>(Arrays.asList(cores));
        printList(list1);

        String[] cores2 = { "dourado", "prata", "marron", "cinza" };
        List<String> list2 = new LinkedList<>(Arrays.asList(cores2));
        printList(list2);

        // Concatena a list1 com list2
        list1.addAll(list2);

        // Imprime a list1 concatenada com a list2 
        printList(list1);
    }

    public static void printList(List<String> list)
    {
        for (String e: list)
            System.out.println(e);
    }
}
