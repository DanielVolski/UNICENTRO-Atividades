package E2;

public class Robo implements Falante {

    @Override
    public void falar() {
        System.out.println("Olá! Eu sou um robô");
    }

    @Override
    public String seuIdioma() {
        return "Grego";
    }

    public void reboot() {
        System.out.println("Rebootando...");
    }
    
}
