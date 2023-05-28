/**
 * Classe Jogador - Trabalho de POOI
 * Classe responsável por definir caraterísticas do Jogador
 * @author Daniel Flavio Volski Daum
 * @version 1.0
 */

package jogodavelha;

public class Jogador {
    
    private char marcador;
    private String nome;
    
    /**
     * Esse construtor inicializa o objeto jogador com os seguintes
     * parâmetros
     * @param nome nome do jogador
     * @param marcador marcador definido para o jogador
     */
    public Jogador(String nome, char marcador) {
        this.nome = nome;
        this.marcador = marcador;
    }

    /**
     * Método get para o atributo nome
     * @return o atributo nome
     */
    public String getNome() {
        return nome;
    }
    /**
     * Método get para o atributo marcador
     * @return o atributo marcador
     */
    public char getMarcador() {
        return marcador;
    }

    /**
     * Método set para o atributo nome
     * @param nome nome do jogador
     */
    public void setNome(String nome) {
        this.nome = nome;
    }
    /**
     * Método set para o atributo marcador
     * @param marcador marcador
     */
    public void setMarcador(char marcador) {
        this.marcador = marcador;
    }
}
