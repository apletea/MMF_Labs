package lab9;

import java.util.Set;
import java.util.TreeSet;

/**
 * Created by apletea on 27.4.17.
 */

class P{
    void show(int i){
        System.out.println("1");
    }
}

public class B extends P  {

    public void show(int i){
        System.out.println("2");
    }

    public static void main(String ... args) {
        Object ob = new TreeSet();
        System.out.println(ob instanceof TreeSet);
        System.out.println(ob instanceof Set);
    }

}
