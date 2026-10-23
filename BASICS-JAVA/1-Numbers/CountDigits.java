/*
Count Digits

Given a non-negative integer n, return how many digits it has.

Example:
n = 10050
Output: 5
*/
import java.util.*;

public class CountDigits{
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        int count=0;
        while(n>0){
            count++;
            n=n/10;
        }
        System.out.println(count);
        sc.close();
    }
}
