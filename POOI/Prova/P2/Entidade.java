public class Entidade {
    protected int hp = 100;

    public void atacar(Entidade e) {
        e.hp -= 10;
    }
}