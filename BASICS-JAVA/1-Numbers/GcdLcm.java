/*
GCD and LCM

Given two positive integers a and b, print their GCD and LCM.

Example:
a = 12, b = 18
Output: 6 36
*/
import java.util.*;

public class GcdLcm{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        long a=sc.nextLong();
        long b=sc.nextLong();
        long g=gcd(a,b);
        long l=a/g*b;
        System.out.println(g+" "+l);
        sc.close();
    }

    public static long gcd(long a,long b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
}
