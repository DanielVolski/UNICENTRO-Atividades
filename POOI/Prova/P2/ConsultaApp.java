

public class ConsultaApp {
    public static void main(String[] args) {
        Paciente paciente1 = new Paciente("Robervaldo", 24);
        Dentista dentista1 = new Dentista("Gumercinda", paciente1);
        Consulta consulta = new Consulta();

        consulta.atender(dentista1);
    }
}
