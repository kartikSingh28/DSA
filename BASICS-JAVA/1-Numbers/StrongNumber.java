/*
Strong Number

n is a Strong number if the sum of the factorials of its digits equals n.
Return true/false.

Example:
n = 145
Output: true
*/
import java.util.*;

public class StrongNumber{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();

        boolean res=solve(n);
        System.out.println(res);
        sc.close();
    }
    public static boolean solve(int n){
        if(n==0){
            return false;
        }
        long sum=0;
        long x=(long)n;
        while(n>0){
            int d=n%10;
            sum+=(long)fact(d);
            n=n/10;
        }
        if(x==sum){
            return true;
        }else{
            return false;
        }
    }

    public static long fact(int n){
        long prdct=1;
        for(int i=2;i<=n;i++){
            prdct=prdct*i;
        }
        return prdct;
    }
}