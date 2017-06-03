import java.time.ZonedDateTime;
import java.util.Date;
import java.util.Scanner;

/**
 * Created by apletea on 11.3.17.
 */

/**
 * @author Kamarouski Dzmitry
 *
 */

/*Найти число, цифры в котором идут в строгом порядке возрастания. Если
таких чисел несколько, найти первое из них*/
public class lab3 {
     public static void main(String ... args){
          Scanner sc = new Scanner(System.in);
          while (true){
               int a = sc.nextInt();
               if (isSatisfied(a)) {
                    System.out.println(a);
                    Date d = new Date();
                    System.out.println("Комаровский Дмитрий " + ZonedDateTime.now());
                    return;
               }
          }
     }

     private static boolean isSatisfied(int a){
          int n = a%10;
          a /= 10;
          while(a!=0){
               if (a%10 != n-1)
                    return false;
               n = a%10;
               a /= 10;
          }
          return true;
     }
}
