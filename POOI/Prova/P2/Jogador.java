public class Jogador extends Entidade {
    @Override
    public void atacar(Entidade e) {
        e.hp -= 20;
    }
}
