/*
Count Divisors

Given n, return the number of divisors of n.
Constraints: 1 <= n <= 10^9

Example:
n = 12
Output: 6
*/
import java.util.*;

public class CountDivisors{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int count=0;
        for(long i=1;i*i<=n;i++){
            if(n%i==0){
                if(i==n/i){
                    count++;
                }else{
                    count+=2;
                }
            }
        }
        System.out.println(count);
        sc.close();
    }
}
