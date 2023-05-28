package E1;
public class testeInstrumento {
    public static void main (String args[]) {
        Instrumento viola = new Corda();
        Instrumento cajon = new Percussao();
        Instrumento ocarina = new SoproMadeira();
        Instrumento clarinete = new SoproMetal(); 

        Instrumento instrumentos[] = {viola, cajon, ocarina, clarinete};

        sinfonia(instrumentos);

    }

    public static void sinfonia (Instrumento listaInstrumentos[]) {
        for (int i = 0; i < listaInstrumentos.length; i++) {
            listaInstrumentos[i].nome();
            listaInstrumentos[i].afinar();
            listaInstrumentos[i].tocar();
            System.out.println();
        }
    }
}
