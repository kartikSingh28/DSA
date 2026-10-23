/*
Trailing Zeros in Factorial

Given n, return the number of trailing zeros in n!.
Constraints: 0 <= n <= 10^9

Example:
n = 25
Output: 6
*/

import java.util.*;

public class TrailingZerosInFactorial{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        long n=sc.nextInt();
        long count=0;
        while(n>0){
            n=n/5;
            count+=n;
        }
        System.out.println(count);
        sc.close();
    }
}
