public class exercicio4 {
    public static void main (String args[]) {
        int ab, cd, ef;
        
        for(int i=1000; i < 10000; i++) {
            ab = (int)i/100;
            cd = (int)((((float)i/100) - (i/100)) * 100);
            ef = ab + cd;
            if(Math.pow(ef, 2) == i) {
                System.out.println(i);
            }
        }
    }
}