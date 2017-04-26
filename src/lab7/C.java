package lab7;

import java.util.Scanner;

/**
 * Created by apletea on 6.4.17.
 */
public class C {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String fileName = sc.nextLine();
        String mask =sc.nextLine();
        for (int i = 0, j = 0 ; i < mask.length() && j <fileName.length() ;++i, ++j){
            char sym = mask.charAt(i);
            if (sym == '?')
                continue;
            if (sym == '*'){
                while (j < fileName.length() &&  i+1 < mask.length() && fileName.charAt(j)!= mask.charAt(i+1) ){
                    j++;
                }
                continue;
            }
            if (sym != fileName.charAt(j)){
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
