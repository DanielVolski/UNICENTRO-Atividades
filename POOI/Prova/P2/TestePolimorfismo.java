public class TestePolimorfismo {
    public static void main(String args[]) {
        Entidade jogador = new Jogador();
        Entidade inimigo = new Inimigo();

        System.out.println("HP do jogador: " + jogador.hp);
        System.out.println("HP do inimigo: " + inimigo.hp);
        
        jogador.atacar(inimigo);
        inimigo.atacar(jogador);

        System.out.println("HP do jogador: " + jogador.hp);
        System.out.println("HP do inimigo: " + inimigo.hp);
    }
}
