class exercicio2 {
    public static void main (String args[]) {
        for(int i=1; i<15; i++){
            String c = (i % 2 == 0) ? "**" : "*";
            System.out.println(c);
        }
    }
}