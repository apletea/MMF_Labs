package forNick.lab3;

/**
 * Created by apletea on 31.5.17.
 */
public class C {
    public static void main(String ... args){

    }

    static class Ratio{
        int m;
        int n;

        public int getM() {
            return m;
        }

        public void setM(int m) {
            this.m = m;
        }

        public int getN() {
            return n;
        }

        public void setN(int n) {
            this.n = n;
        }

        @Override
        public String toString() {
            return "Ratio{" +
                    "m=" + m +
                    ", n=" + n +
                    '}';
        }

        public Ratio(int m, int n) {
            this.m = m;
            this.n = n;
        }

        public Ratio(){
            this.m = 0;
            this.n = 0;
        }

    }
}
