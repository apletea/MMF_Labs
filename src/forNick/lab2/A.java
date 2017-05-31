package forNick.lab2;

import java.time.ZonedDateTime;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by apletea on 31.5.17.
 */

/**
 * @author Gressky Nikita
 *
 */
public class A {
    /*Найти число, в  котором число различных цифр минимально. Если таких
    //чисел несколько, найти первое из них.*/
    public static void main(String ... args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int arr [] = new int[n];
        for (int i = 0 ; i < n; ++i){
            arr[i] = sc.nextInt();
        }
        int count[] = new int[n];
        for (int i = 0; i < n; ++i){
            Set<Integer> st = new HashSet<>();
            int tmp  = arr[i];
            while (tmp > 0){
                st.add(tmp%10);
                tmp /= 10;
            }
            count[i] = st.size();
        }
        int ans_i = 0;
        for (int i = 1; i < n; ++i){
            if (count[i] < count[ans_i])
                ans_i = i;
        }
        System.out.println(arr[ans_i]);
        System.out.println("Гресскй Никита " + ZonedDateTime.now());

    }

}
