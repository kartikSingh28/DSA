/*
Palindrome Number

Given an integer n, return true if it reads the same forwards and backwards.

Example:
n = 121  -> true
n = 123  -> false
*/
import java.util.*;

public class PalindromeNumber{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int x=n;
        int rev=0;
        while(n>0){
            int d=n%10;
            rev=rev*10+d;
            n=n/10;
            
        }
        if(rev==x){
            System.out.println("Is Pallindrome");
        }else{
            System.out.println("Not a Pallindrome");
        }
        sc.close();
    }

}
