public class exercicio3 {
    public static void main(String args[]) {
        double media = 0;
        double[] valores = {2.3, 42.12, 4.5, 78.53, 259.01};

        for(double v: valores)
            media += v;
        media = media / 5;

        System.out.println(media);
    }
}
