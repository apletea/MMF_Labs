package lab7;

import java.util.Scanner;

/**
 * Created by apletea on 6.4.17.
 */
public class A {
    public static void main(String ... args){
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int delOrInsert = sc.nextInt();
        char symbol = sc.next().charAt(0);
        char replaceAfter = sc.next().charAt(0);
        System.out.println(makeTask(str, delOrInsert,  symbol, 'a'));
    }

    private static String makeTask(String str, int delOrInsert, char symbol , char replaceAfter) {
        String res = "";
        if (delOrInsert == 1){
           res = str.replaceAll(symbol+"","");
        }
        else {
           res = str.replaceAll(replaceAfter+"",replaceAfter+symbol+"");
        }
        return res;
    }
}
