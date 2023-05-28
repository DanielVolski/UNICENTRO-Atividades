public class Dentista {
    private String nome;
    private Paciente paciente;

    Dentista(String nome1, Paciente paciente1) {
        nome = nome1;
        paciente = paciente1;
    }

    public String getNome() {
        return this.nome;
    }

    public String getPaciente() {
        return this.paciente.getNome();
    }
}
