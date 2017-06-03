package forNick.lab2;

import java.util.Scanner;

/**
 * Created by apletea on 31.5.17.
 */
public class C {
    /*Найти сумму элементов матрицы, расположенных между первым и вторым
    положительными элементами каждой строки.*/
    public static void main(String ... args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int arr[][] = new int[n][n];
        for (int i = 0; i < n; ++i){
            int sum = 0;
            int k = 0;
            for (int j = 0; j < n; ++j){
                arr[i][j] =  (int )(Math.random() * 2*n -n );;
                if (arr[i][j] > 0 & k == 0)
                    sum+=arr[i][j];
                if (arr[i][j] < 0 & sum!=0)
                    k=1;
                System.out.print(arr[i][j] + " ");
            }
            System.out.println("сумма равна :" +sum);
            System.out.println("");
        }


    }

}
