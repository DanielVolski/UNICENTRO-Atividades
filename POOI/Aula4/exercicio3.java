public class exercicio3 {
    public static void main (String args[]) {
        int soma = 0;
        
        while (soma < 100) {
            for (int i=1; i <= 100; i=i+2){
                System.out.println(i);
                soma = soma + i;
            }
        }

        System.out.println(soma);

    }
}