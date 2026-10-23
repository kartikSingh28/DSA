/*
Binary to Decimal

Given a binary string s, return its decimal value.

Example:
s = "1101"
Output: 13
*/

import java.util.*;

public class BinaryToDecimal{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        int n=s.length();

        int res=0;
        for(int i=0;i<n;i++){
            int bit=s.charAt(i)-'0';
            res=res*2+bit;
        }
        System.out.println(res);
        
        sc.close();
    }
}