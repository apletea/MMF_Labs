package forNick.lab3;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by apletea on 31.5.17.
 */
public class C {


   /* Определить класс Дробь в  виде пары (m, n) с  коэффициентами типа
    Комплексное число. Объявить и инициализировать массив из k дробей, вве-
    сти/вы­вести значения для массива дробей. Создать массив/список/множест-
    во объектов и передать его в метод, который изменяет каждый элемент мас-
    сива с четным индексом путем добавления следующего за ним элемента.*/
    public static void main(String ... args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        List<Ratio> arr= new ArrayList<>();
        for (int i  = 0 ; i < k; ++i){
            arr.add(i,new Ratio((int)(Math.random()*50),(int)(Math.random()*50+1)));
            System.out.println(arr.get(i));
        }
        System.out.println("меняем");
        for (int i = 0; i < arr.size(); i+=2){
            arr.add(i,new Ratio((int)(Math.random()*50),(int)(Math.random()*50+1)));
        }
        for (int i = 0; i < arr.size(); ++i){
            System.out.println(arr.get(i));
        }

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
                    "" + m +
                    "/" + n +
                    '}';
        }

        public Ratio(int m, int n) {
            this.m = m;
            this.n = n;
        }

        public Ratio(){
            this.m = 0;
            this.n = 1;
        }

    }
}
