/**
 * Classe Tabuleiro - Trabalho POOI
 * Classe que possui os principais atributos e métodos
 * para o funcionamento do tabuleiro do jogo
 * @author Daniel Flavio Volski Daum
 * @version 1.0
 */

package jogodavelha;

public class Tabuleiro {

    private final int LINHAS = 3, COLUNAS = 3;
    
    private char tabuleiro[][] = new char[LINHAS][COLUNAS];

    /**
     * Esse construtor inicializa o tabuleiro com espaços
     * em branco
     */
    public Tabuleiro() {
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                tabuleiro[i][j] = ' ';
            }
        } 
    }

    /**
     * Esse método realiza a exibição do tabuleiro
     */
    public void mostraTabuleiro() {
        //System.out.print("\033[H\033[2J");
        System.out.println();
        System.out.println("   1   2   3   ");
        System.out.println("1  " + getTabuleiro(0, 0) + " * " + getTabuleiro(0, 1) + " * " + getTabuleiro(0, 2));
        System.out.println("  * * * * * * ");
        System.out.println("2  " + getTabuleiro(1, 0) + " * " + getTabuleiro(1, 1) + " * " + getTabuleiro(1, 2));
        System.out.println("  * * * * * * ");
        System.out.println("3  " + getTabuleiro(2, 0) + " * " + getTabuleiro(2, 1) + " * " + getTabuleiro(2, 2));
        System.out.println();
    }

    /**
     * Método get para o atributo linhas
     * @return atributo LINHAS
     */
    public int getLinhas() {
        return LINHAS;
    }
    /**
     * Método get para o atributo colunas
     * @return atributo Colunas
     */
    public int getColunas() {
        return COLUNAS;
    }
    /**
     * Método get para o valor especificado pela linha e coluna
     * @param linha linha onde se encontra o valor solicitado
     * @param coluna coluna onde se encontra o valor solicitado
     * @return o valor especificado pelas linhas e colunas
     */
    public char getTabuleiro(int linha, int coluna) {
        return tabuleiro[linha][coluna];
    }

    /**
     * Método set para o tabuleiro
     * @param marcador que será preenchido no espaço especificado
     * @param linha linha onde será inserido o marcador
     * @param coluna coluna onde será inserido o marcador
     */
    public void setTabuleiro(char marcador, int linha, int coluna) {
        tabuleiro[linha][coluna] = marcador;
    }
}