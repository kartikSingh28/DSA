/*
Decimal to Binary

Given a non-negative integer n, return its binary representation as a string.

Example:
n = 13
Output: "1101"
*/
import java.util.*;

public class DecimalToBinary{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        StringBuilder sb=new StringBuilder();
        while(n>0){
            int bit=n%2;
            sb.append(bit);
            n=n/2;
        }
        sb.reverse();
        System.out.println(sb.toString());
        sc.close();
    }
}