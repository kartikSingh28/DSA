/*
Primes up to N

Print all prime numbers from 1 to n.
Constraints: 1 <= n <= 10^6

Example:
n = 20
Output: 2 3 5 7 11 13 17 19
*/
import java.util.*;

class PrimesUpToN{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int count;

        for(int i=2;i<=N;i++){
            count=0;
            for(int j=1;j<=i;j++){
                if(i%j==0)count++;
            }
            if(count==2){
                System.out.print(i+" ");
            }
            
        }
        sc.close();
    }
}