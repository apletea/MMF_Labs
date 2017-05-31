package forNick.lab3;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by apletea on 31.5.17.
 */
public class B {
    /*Определить класс Полином степени n. Объявить массив/список/множество
    из m полиномов и определить сумму полиномов массива.*/
    public static void main(String ... rags){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Polinom arr[] = new Polinom[m];
        for (int i = 0 ; i < m; ++i){
            int tmp[] = new int[n];
            for (int j = 0; j < n; ++j){
                tmp[j] = (int)(Math.random()*100-50);
            }
            arr[i] = new Polinom(tmp);
        }
        Polinom ans = new Polinom(n);
        for (int i = 0; i < m ;++i){
            ans.sum(arr[i]);
        }
        System.out.println(ans);
    }

    static class Polinom{
        int arr[];
        Polinom(int a){
            arr = new int[a];
        }

        Polinom( int arr[]){
            this.arr = arr;
        }

        public int[] getArr() {
            return arr;
        }

        public void setArr(int[] arr) {
            this.arr = arr;
        }

        @Override
        public String toString() {
            return "Polinom{" +
                    "arr=" + Arrays.toString(arr) +
                    '}';
        }

        void sum(Polinom a){
            for (int i = 0; i <a.arr.length;++i ){
                this.arr[i] += a.arr[i];
            }
        }

        void substraction(Polinom a){
            for (int i = 0; i <a.arr.length;++i ){
                this.arr[i] += a.arr[i];
            }
        }

        void multiply(Polinom a){
            for (int i = 0; i <a.arr.length;++i ){
                this.arr[i] *= a.arr[i];
            }
        }

        void dision(Polinom a){
            for (int i = 0; i <a.arr.length;++i ){
                this.arr[i] /= a.arr[i];
            }
        }
    }
}
