public class Turma {
    private String curso, disciplina;
    //Setters
    public void setCurso(String nomeCurso) {
        curso = nomeCurso;
    }
    public void setDisciplina(String nomeDisciplina) {
        disciplina = nomeDisciplina;
    }
    //Getters
    public String getCurso() {
        return curso;
    }
    public String getDisciplina() {
        return disciplina;
    }

    public void exibeDados() {
        System.out.println("Curso: "+getCurso()+"\nDisciplina: "+getDisciplina());
    }
}
