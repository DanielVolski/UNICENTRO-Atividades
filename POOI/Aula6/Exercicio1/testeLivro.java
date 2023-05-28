public class testeLivro {
    public static void main(String args[]) {
        Livro livro = new Livro();

        livro.setAutor("George Orwell");
        livro.setTitulo("1984");

        System.out.println("Autor: "+livro.getAutor()+"\nTitulo: "+livro.getTitulo());
    }
}