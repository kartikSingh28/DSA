/*
Prime Check

Given n, return true if n is prime.
Constraints: 1 <= n <= 10^9

Example:
n = 29  -> true
n = 1   -> false
*/
import java.util.*;

public class PrimeCheck{
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);

        int n=sc.nextInt();
        int count=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                count++;
            }
        }
        if(count==2){
            System.out.println("Prime number");
        }else{
            System.out.println("Not a Prime Number");
        }
        sc.close();
    }
}
