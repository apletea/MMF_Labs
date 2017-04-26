package lab6;

/**
 * Created by apletea on 6.4.17.
 */
public class Main {
    public static void main(String ... args){
        Flattop flattop = new Flattop();
        System.out.println(flattop);
        flattop.shoot();
        flattop.upFlyyes();
        flattop.move();
        flattop.stop();
    }
}
