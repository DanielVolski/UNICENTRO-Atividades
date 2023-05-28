import java.util.Scanner;

public class TesteException {

    public static double raiz(double radicando, double indice) throws ExceptionA, ExceptionB, ExceptionC {
        return Math.pow(radicando, 1 / indice);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        try {
            int radicando = sc.nextInt();
            int indice = sc.nextInt();
            double resultado = raiz(radicando, indice);
            System.out.println(resultado);
        } catch (ExceptionC e) {
            System.out.println(e);
        } catch (ExceptionB e) {
            System.out.println(e);
        } catch (ExceptionA e) {
            System.out.println(e);
        }
        sc.close();
    }
}
