public class exercicio5 {
    public static void main(String args[]) {
        int[] array = new int[] { 23, 72, 45, 64, 446, 29, 17, 6 };
        int maiorDiferenca = 0, index1 = 0, index2 = 0;

        /*
         * Procura no vetor a sequencia de dois índices consecutivos que possuem a maior
         * diferença entre eles
         */
        for (int i = 0; i < array.length - 1; i++) {
            int diferenca = array[i] - array[i + 1]; // Armazena a diferença entre os dois valores no índice i
            if (diferenca < 0) { // Confere se a diferença é negativa
                if ((diferenca * (-1)) > maiorDiferenca) {
                    maiorDiferenca = diferenca * (-1);
                    index1 = i;
                    index2 = i + 1;
                }
            } else { // Processo realizado caso a diferença seja positiva
                if (diferenca > maiorDiferenca) {
                    maiorDiferenca = array[i] - array[i + 1];
                    index1 = i;
                    index2 = i + 1;
                }
            }
        }
        System.out.println(array[index1] + " " + array[index2]);
        System.out.println(index1 + "" + index2);
    }
}
