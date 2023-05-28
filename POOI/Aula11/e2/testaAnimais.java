package e2;

public class testaAnimais {
    public static void main(String[] args) {
        // Instancia os objetos
        Cachorro cachorro = new Cachorro();
        Gato gato = new Gato();
        Preguica preguica = new Preguica();

        cachorro.emitirSom();
        gato.emitirSom();
        preguica.emitirSom();
    }
}
