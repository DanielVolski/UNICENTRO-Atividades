/**
 * Interface GerenciaJogadores - Trabalho POOI
 * Interface com os métodos para gravar o nome dos jogadores
 * em um arquivo txt
 * @author Daniel Flavio Volski Daum
 * @version 1.0
 */
package armazenamento;

public interface GerenciaJogadores {
    
    /**
     * Método para gravar nome de jogadores em um arquivo txt
     * @param nomeJogador Nome do jogador que será gravado
     */
    public void gravarNome(String nomeJogador);
}
