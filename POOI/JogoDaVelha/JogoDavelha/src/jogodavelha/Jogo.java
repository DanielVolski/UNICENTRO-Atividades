/** 
 * Classe Jogo - Trabalho POOI
 * Nesta classe se encontra toda a lógica de funcionamento do jogo
 * @author Daniel Flavio Volski Daum
 * @version 1.0
 */
package jogodavelha;

import armazenamento.GerenciaJogadoresArquivo;
import entradadados.Console;

public class Jogo {

    private final int NJOGADORES = 2;

    private int linha, coluna, jogadorDaVez = 0;
    private boolean ganhador = false;

    private Jogador[] jogadores = new Jogador[NJOGADORES];
    private Tabuleiro tab = new Tabuleiro();
    private Jogada jogada = new Jogada();
    private GerenciaJogadoresArquivo arq = new GerenciaJogadoresArquivo();

    public void inicia() {
        System.out.print("Jogador 1, insira seu nome: ");
        jogadores[0] = new Jogador(Console.readString(), 'X');
        arq.gravarNome(jogadores[0].getNome());
        System.out.print("Jogador 2, insira seu nome: ");
        jogadores[1] = new Jogador(Console.readString(), 'O');
        arq.gravarNome(jogadores[1].getNome());

        while (!ganhador) {
            do {
                try {
                    System.out.print("\033[H\033[2J");
                    tab.mostraTabuleiro();
                    System.out.print(jogadores[jogadorDaVez].getNome() + "(" + jogadores[jogadorDaVez].getMarcador() + ")" + " selecione uma linha: ");
                    linha = Console.readInt();
                    System.out.print(jogadores[jogadorDaVez].getNome() + "(" + jogadores[jogadorDaVez].getMarcador() + ")" + " selecione uma coluna: ");
                    coluna = Console.readInt();

                    if (jogada.validaJogada(jogadores[jogadorDaVez], tab, linha - 1, coluna - 1))
                        break;
                        
                    System.out.println("Jogada inválida! Posição já ocupada ou inexistente. Jogue novamente!");
                    delay(1500);
                } catch (RuntimeException e) {
                    System.out.println(e);
                    delay(1500);
                }
            } while (true);

            jogada.efetuaJogada(jogadores[jogadorDaVez], tab, linha - 1, coluna - 1);

            if (checaVitoria(jogadores[jogadorDaVez])) {
                tab.mostraTabuleiro();
                System.out.println(jogadores[jogadorDaVez].getNome() + " ganhou o jogo!");
                break;
            }

            if (checaEmpate()) {
                tab.mostraTabuleiro();
                System.out.println("Jogo finalizado por empate!");
                break;
            }

            jogadorDaVez++;
            if (jogadorDaVez > 1)
                jogadorDaVez = 0;

        }

    }

    /**
     * Esse método verifica se algum jogador ganhou
     * 
     * @param jogador
     * @return true se houver um ganhador e false caso não haja
     */
    public boolean checaVitoria(Jogador jogador) {
        // Checa vitória pelas linhas
        if (tab.getTabuleiro(0, 0) == jogador.getMarcador() && tab.getTabuleiro(0, 1) == jogador.getMarcador()
                && tab.getTabuleiro(0, 2) == jogador.getMarcador()) {
            return true;
        }
        if (tab.getTabuleiro(1, 0) == jogador.getMarcador() && tab.getTabuleiro(1, 1) == jogador.getMarcador()
                && tab.getTabuleiro(1, 2) == jogador.getMarcador()) {
            return true;
        }
        if (tab.getTabuleiro(2, 0) == jogador.getMarcador() && tab.getTabuleiro(2, 1) == jogador.getMarcador()
                && tab.getTabuleiro(2, 2) == jogador.getMarcador()) {
            return true;
        }

        // Checa vitória pelas colunas
        if (tab.getTabuleiro(0, 0) == jogador.getMarcador() && tab.getTabuleiro(1, 0) == jogador.getMarcador()
                && tab.getTabuleiro(2, 0) == jogador.getMarcador()) {
            return true;
        }
        if (tab.getTabuleiro(0, 1) == jogador.getMarcador() && tab.getTabuleiro(1, 1) == jogador.getMarcador()
                && tab.getTabuleiro(2, 1) == jogador.getMarcador()) {
            return true;
        }
        if (tab.getTabuleiro(0, 2) == jogador.getMarcador() && tab.getTabuleiro(1, 2) == jogador.getMarcador()
                && tab.getTabuleiro(2, 2) == jogador.getMarcador()) {
            return true;
        }

        // Checa a vitória pelas diagonais
        if (tab.getTabuleiro(0, 0) == jogador.getMarcador() && tab.getTabuleiro(1, 1) == jogador.getMarcador()
                && tab.getTabuleiro(2, 2) == jogador.getMarcador()) {
            return true;
        }
        if (tab.getTabuleiro(0, 2) == jogador.getMarcador() && tab.getTabuleiro(1, 1) == jogador.getMarcador()
                && tab.getTabuleiro(2, 0) == jogador.getMarcador()) {
            return true;
        }

        return false;
    }

    /**
     * Essa classe checa se o tabuleiro está todo preenchido e define empate caso
     * não haja ganhador
     * 
     * @return false caso o tabuleiro ainda possua espaços vazios e true caso o
     *         tabuleiro esteja completo
     */
    public boolean checaEmpate() {
        for (int i = 0; i < tab.getLinhas(); i++) {
            for (int j = 0; j < tab.getColunas(); j++) {
                if (tab.getTabuleiro(i, j) == ' ')
                    return false;
            }
        }
        return true;
    }

    /**
     * Função que pausa a thread por um determinado tempo
     * @param ms tempo que a thread ficará pausada
     */
    public void delay(long ms) {
        try {
            Thread.sleep(ms);
        } catch (InterruptedException exc) {
            System.out.println(exc);
        }
    }
}
