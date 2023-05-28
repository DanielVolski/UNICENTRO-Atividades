package E2;

public class TestaFalantes {
    public static void main(String[] args) {
        Falante f1, f2;                         // Cria duas instâncias da interface Falante
        f1 = new Aluno();                       // Especifica f1 como sendo do tipo Alunos(), já que implementa a interface falante
        f2 = new Robo();                        // Especifica f2 como sendo do tipo Robo(), já que implementa a interface falante
        Entrevistador e = new Entrevistador();  // Cria uma instância do tipo Entrevistador
        e.entrevista(f1);                       // Imprime uma saudação ao aluno, e define uma linguagem para a conversa
        System.out.println("-------------");
        e.entrevista(f2);                       // Imprime uma saudação ao robo, executa o método reboot e define o idioma para a conversa
    }
}
