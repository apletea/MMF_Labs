package task;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by apletea on 2.3.17.
 */
public class JDBC {

     int MIN_NUMBER = 0;
     int MAX_NUMBER = 0;

    public  long  main(int min, int max){
        MIN_NUMBER = min;
        MAX_NUMBER = max;
        return findNumber();
    }

    private  long findNumber() {
        boolean nums[] = sieveOfEratosthenes();
        List<Integer> primes = getPrimes(nums);
        long ans = 1;
        long div1 = 0;
        long div2 = 0;
        for (int i = 0; i  < primes.size(); ++i){
            for (int j = i ; j <primes.size(); ++j){
                long tmp =(long) primes.get(i)*(long)primes.get(j);
                //все палиндромы с чётным количеством разрядов делятся на 11, соответсвенно их проверять не надо
                if (tmp > 1000000000)
                    break;
                if (tmp > ans){
                    if (isPalindrome(tmp)) {
                        ans = tmp;
                        div1 = primes.get(i);
                        div2 = primes.get(j);
                    }
                }
            }
        }
        System.out.println("ans :" + ans + "  " + "divider1:" + div1 + "  divider2:" + div2);
        return ans;
    }

    private  boolean [] sieveOfEratosthenes(){
        boolean nums[] = new boolean[MAX_NUMBER+1];
        Arrays.fill(nums,true);
        nums[0] = false;
        nums[1] = false;
        int w8 = (int)Math.sqrt(MAX_NUMBER);
        for (int i = 3; i < w8; i+=2 ){
            for (int j = Math.max(i-i%2 + 1,MIN_NUMBER - MIN_NUMBER%2 + 1); j < MAX_NUMBER; j+=2){
                if (j%i==0 && j!=i)
                    nums[j] = false;
            }
        }
        return nums;
    }

    private  List<Integer> getPrimes(boolean [] nums){
        List<Integer> primes = new ArrayList<>();
        for (int i = MIN_NUMBER-MIN_NUMBER%2 + 1; i < MAX_NUMBER; i+=2 ){
            if (nums[i]) {
                primes.add(i);
            }
        }
        return primes;
    }

    private  boolean isPalindrome(long number){
        long tmp  = number;
        long sum = 0;
        while(tmp > 0){
            sum  = sum*10 + tmp%10;
            tmp = tmp/10;
        }
        return number == sum;
    }
}
