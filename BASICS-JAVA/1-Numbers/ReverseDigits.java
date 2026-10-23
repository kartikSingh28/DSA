/*
Reverse Digits

Given a non-negative integer n, return the number formed by reversing its digits.

Example:
n = 1230
Output: 321
*/
import java.util.*;
public class ReverseDigits{
    public static void main(String args []){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int rev=0;
        while(n>0){
            int d=n%10;
            rev=rev*10+d;
            n=n/10;
        }
        System.out.println(rev);
        sc.close();
    }
}
