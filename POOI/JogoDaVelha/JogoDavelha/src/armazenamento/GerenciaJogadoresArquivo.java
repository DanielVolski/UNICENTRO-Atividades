/**
 * Classe GerenciaJogadoresArquivos - Trabalho POOI
 * Classe que implementa a interface GerenciaJogadores
 * e efetua a gravação do nome dos jogadores no arquivo
 * txt
 * @author Daniel Flavio Volski Daum
 * @version 1.0
 */

package armazenamento;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class GerenciaJogadoresArquivo implements GerenciaJogadores {

    @Override
    public void gravarNome(String nomeJogador) {
        BufferedWriter writer = null;
        try {
            writer = new BufferedWriter(new FileWriter("NomeDosJogadores.txt", true));
            writer.write(nomeJogador);
            writer.newLine();
        } catch (IOException e) {
            System.out.println("ERRO de I/O" + e);
        } finally {
            try {
                if (writer != null)
                    writer.close();
            } catch (IOException e) {
                System.out.println("Fechando arquivo! " + e);
            }
        }
        
    }  
}
