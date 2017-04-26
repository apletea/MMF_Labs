package lab7;

import java.util.Scanner;

/**
 * Created by apletea on 6.4.17.
 */
public class B {
     public static void main(String ... args){
         Scanner sc = new Scanner(System.in);
         String str = sc.nextLine();
         String strs[] = str.split(" ");
         for (char i = 'а'; i <= 'я'; ++i){
             boolean isWrite = false;
             for (int j = 0; j < strs.length; ++j){
                 String tmp = strs[j];
                 tmp = tmp.trim();
                 if (tmp.charAt(0)==i) {
                     System.out.print(" " + tmp);
                     isWrite = true;
                 }
             }
             if (isWrite)
             System.out.println("");
         }
    }
}
