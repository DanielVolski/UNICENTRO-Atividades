package Prova;

public class Q4 {
    public static void main(String args[]) {
        System.out.println("Media de kilometros percorridos: " + calcMedia(102, 22, 39));
        System.out.println("Media de kilometros percorridos: " + calcMedia(19, 100, 42));
    }

    public static double calcMedia(double ...numeros) {
        double resultado = 0;
        for (double d: numeros)
            resultado += d;
        return resultado/numeros.length;
    }
}
