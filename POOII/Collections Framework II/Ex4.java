import java.util.*;
class ExemploTreeSet {
  public static void main(String[] args) {
    char[] chrs = { 'V', 'J', 'L', 'E', 'E'};
    // Cria um conjunto de árvore e um conjunto hash.
    TreeSet<Character> ts = new TreeSet<Character>();
    HashSet<Character> hs = new HashSet<Character>();
    System.out.print("Conteúdo de chrs:      ");
    for(char ch : chrs)
      System.out.print(ch + "  ");
    System.out.println();
    // Primeiro, adiciona os caracteres ao conjunto hash.
    for(char ch : chrs)
      hs.add(ch);
    System.out.println("Conteúdo do conjunto hash: " + hs);
    

    // A saída para este caso é V, J, L, E já que a classe Set cujo TreeSet herda trabalha com operações
    //de conjunto, sendo assim elimina qualquer tipo de repetição
    for(char ch : chrs)
      ts.add(ch);
    System.out.println("Conteúdo do conjunto de árvore: " + ts);
  }
}