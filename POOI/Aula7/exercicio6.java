public class exercicio6 {
    public static int soma(int ... args) {
        int soma = 0;
        for (int i : args) 
            soma += i;
        return soma;
    }
    public static void main(String args[]) {
        
        System.out.println(soma(1, 2, 3, 4));
    }
}
