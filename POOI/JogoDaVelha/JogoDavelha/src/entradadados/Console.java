/**
 * Classe console - Trabalho POOI
 * Classe responsável pela entrada de dados
 * @author Daniel Flavio Volski Daum
 * @version 1.0
 */

package entradadados;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Console {
    
    public static String readString() {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException("ERRO na leitura de dados!");
        }
    }
    
    public static int readInt() {
        String str = readString();
        
        try {
            return Integer.parseInt(str);
        } catch (NumberFormatException e) {
            throw new RuntimeException(str + " é inválido!");
        }
    }
}
