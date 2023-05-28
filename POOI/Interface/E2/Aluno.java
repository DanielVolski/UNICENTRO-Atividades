package E2;

public class Aluno extends Pessoa implements Falante {
    
    @Override
    public void falar() {
        System.out.println("Olá, eu sou aluno de Ciência da Computação!");
    }

    @Override
    public String seuIdioma() {
        return "Paquistanês";

    }

    public void identificarSe() {
        System.out.println("Olá! Meu nome é " + getNome());
    }
    
}
