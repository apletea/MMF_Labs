package norma;

import java.util.Scanner;

/**
 * Created by apletea on 13.2.17.
 */
/*6.	 Вычислить норму матрицы.*/
public class Solution {

    public static int findNorm(int [][] nums){
        int ansSquared = 0;
        for (int i = 0 ; i < nums.length; ++i){
            for (int j = 0; j < nums[0].length; ++j){
                ansSquared += nums[i][j]*nums[i][j];
            }
        }
        return (int) Math.sqrt(ansSquared);
    }

    public static void main(String ... args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int tmp[][] = new int[n][n];
        for (int i =0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                tmp[i][j] = sc.nextInt();
            }
        }
        System.out.println(findNorm(tmp));
    }

}
