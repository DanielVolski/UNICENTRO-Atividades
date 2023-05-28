public class Retangulo extends TwoDShape{
    public double area() {
        return getAltura() * getLargura();
    }
    public boolean checaQuadrado() {
        if (getAltura() == getLargura()) {
            return true;
        }
        return false;
    }  
}
