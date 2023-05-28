import java.util.Scanner;

public class exercicios {
    
    public static void exercicio1() {
        for (int i=10; i <= 25; i++) {
            System.out.println(i);
        }
    }

    public static void exercicio2() {
        for(int i=1; i<15; i++){
            String c = (i % 2 == 0) ? "**" : "*";
            System.out.println(c);
        }
    }

    public static void exercicio3() {
        int soma = 0;
        while (soma < 100) {
            for (int i=1; i <= 100; i=i+2){
                System.out.println(i);
                soma = soma + i;
            }
        }
        System.out.println(soma);
    }

    public static void exercicio4() {
        int ab, cd, ef;
        for(int i=1000; i < 10000; i++) {
            ab = (int)i/100;
            cd = (int)((((float)i/100) - (i/100)) * 100);
            ef = ab + cd;
            if(Math.pow(ef, 2) == i) {
                System.out.println(i);
            }
        }
    }
    public static void main (String args[]) {
        Scanner sc = new Scanner(System.in);
        
        for(int i=1; i <= 4; i++) {
            System.out.println(i + " - Exercicio " + i);
        }
        
        int escolha = sc.nextInt();
        while (escolha > 4 || escolha < 0) {
            System.out.println("Digite um valor válido entre 1 e 4:");
            escolha = sc.nextInt();
        }

        sc.close();

        switch(escolha) {
            case 1:
                exercicio1();
                break;
            case 2:
                exercicio2();
                break;
            case 3:
                exercicio3();
                break;
            case 4:
                exercicio4();
                break;
        }
    }
}
        
    