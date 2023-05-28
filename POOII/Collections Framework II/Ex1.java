import java.util.*;

public class Ex1
{
    public static void main(String args[])
    {
        List<String> names = new ArrayList<>();
        
        names.add("Ronaldo");
        names.add("Jurema");
        names.add("Juvencio");
        names.add("Rivaldina");

        // Cria um ListIterator com o cursor apontando para o final
        ListIterator<String> names_itr = names.listIterator(names.size());

        // Imprime a lista ao contrário
        while (names_itr.hasPrevious())
            System.out.println(names_itr.previous());
    }
}