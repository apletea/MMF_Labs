package by.Kamarouski;

import java.util.*;

/**
 * Created by apletea on 12.2.17.
 */
/*Все трехзначные числа, в  десятичной записи которых нет одинаковых
цифр.*/

public class Solution {

    public static List<Integer> isSateisfied(int [] nums ){
        List<Integer> ans = new ArrayList<>();
        ans = checkByConditions(nums);
        return ans;
    }

    private static List<Integer> checkByConditions(int [] nums) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0 ; i < nums.length; ++i){
            if (nums[i]>99 & nums[i]<1000){
                if (satesfiedToSecondCondition(nums[i])){
                    ans.add(nums[i]);
                }
            }
        }
        return ans;
    }

    private static boolean satesfiedToSecondCondition(int num) {
        Set<Integer> tmp = new HashSet<>();
        for (int i = 0; i < 3; ++i){
            tmp.add(num%10);
            num /= 10;
        }
        return tmp.size()==3;
    }

    public static void main(String ... args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int tmp[] = new int[n];
        for (int i = 0; i < n; ++i){
            tmp[i] = sc.nextInt();
        }
        System.out.println(isSateisfied(tmp));

    }
}
