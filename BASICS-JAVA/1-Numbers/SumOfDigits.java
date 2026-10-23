/*
Sum of Digits

Given a non-negative integer n, return the sum of its digits.

Example:
n = 9875
Output: 29
*/
import java.util.*;

public class SumOfDigits{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=d;
            n=n/10;
        }
        System.out.println(sum);
        sc.close();
    }
}