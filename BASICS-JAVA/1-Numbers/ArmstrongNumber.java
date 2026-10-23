/*
Armstrong Number

n is an Armstrong number if the sum of each digit raised to the power
(number of digits) equals n. Return true/false.

Example:
n = 153
Output: true
*/
import java.util.*;

public class ArmstrongNumber{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        boolean res=isArmstrong(n);
        System.out.println(res);
        sc.close();
    }

    public static boolean isArmstrong(int n){
        int x=n;
        int k=countDigits(n);
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=(int)Math.pow(d,k);
            n=n/10;
        }
        return sum==x;
    }

    public static int countDigits(int n){
        int count=0;
        while(n>0){
            count++;
            n=n/10;
        }
        return count;
    }
}