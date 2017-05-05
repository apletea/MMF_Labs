package lab10;

import java.util.Scanner;

/**
 * Created by apletea on 3.5.17.
 */
public class B {
    public static void main(String []rgs){
        autoStop autoStop = new autoStop();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 1 ; i < n; ++i){
            autoStop.newCar(i);
            if (i%3==0)
                autoStop.outCar((i+10)%6 + i%3);
        }
    }
}

class autoStop{
    node head = new node();

    public void newCar(Object car){
        int i  = 1;
        node tmp = head;
        node prev = null;
        while (tmp != null && !tmp.isEmpty ){
            i++;
            prev = tmp;
            tmp = tmp.next;
        }
        if (tmp == null) {
            tmp = new node(car);
            prev.next = tmp;
        }
        else
            tmp.isEmpty = false;
        System.out.println("машина заехала на место " + i);
    }

    public void outCar(int place){
        node tmp = head;
        for (int i = 1; i < place; ++i){
            tmp = tmp.next;
        }
        tmp.isEmpty = true;
        System.out.println("машина уехала с места " + place);
    }
}

class node{
    node next;
    boolean isEmpty;
    node(){
        this.isEmpty = true;
    }
    node (Object a){
        this.isEmpty = false;
    }
}
