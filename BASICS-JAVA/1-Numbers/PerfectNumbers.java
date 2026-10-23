/*
Perfect Number

n is Perfect if the sum of its proper divisors (all divisors except n) equals n.
Return true/false.

Example:
n = 28
Output: true
*/
import java.util.*;

public class PerfectNumbers{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=0;
        for(int i=1;i<n;i++){
            if(n%i==0){
                sum+=i;
            }
        }
        if(sum==n){
            System.out.println(n+"is  a perfect number");
        }else{
            System.out.println("Not a perfect Number");
        }

        sc.close();
    }
}
