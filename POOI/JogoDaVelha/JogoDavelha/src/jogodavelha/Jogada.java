/**
 * Classe Jogada - Trabalho de POOI
 * Classe responsável por validar e realizar a jogada
 * @author Daniel Flavio Voslki Daum
 * @version 1.0
 */

package jogodavelha;

public class Jogada {

    /**
     * Esse método é responsável por efetuar a jogada no tabuleiro
     * baseado no jogador e nas coordenadas selecionadas
     * @param jogador Jogador que está efetuando a jogada
     * @param tabuleiro Tabuleiro onde a jogada será efetuada
     * @param linha Linha do tabuleiro onde será inserido o marcador
     * @param coluna Coluna do tabuleiro onde será inserido o marcador
     */
    public void efetuaJogada(Jogador jogador, Tabuleiro tabuleiro, int linha, int coluna) {
        tabuleiro.setTabuleiro(jogador.getMarcador(), linha, coluna);
    }

    /**
     * Esse método verifica se a jogada escolhida é válida
     * @param jogador jogador que efetuou a jogada
     * @param tabuleiro tabuleiro o qual deve ser verificado
     * @param linha linha do tabuleiro escolhido pelo jogador
     * @param coluna coluna do tabuleiro escolhido pelo jogador
     * @return True caso a jogada seja válida e false caso seja inválida
     */
    public boolean validaJogada(Jogador jogador, Tabuleiro tabuleiro, int linha, int coluna) {
        if ((linha < tabuleiro.getLinhas() && linha >= 0) && (coluna < tabuleiro.getColunas() && coluna >= 0)) {
            if ((tabuleiro.getTabuleiro(linha, coluna) == ' ')) {
                return true;
            } 
        }
        return false;
    }
}

