/*
Difference of Sums  (Accenture-style)

Given m and n: let A = sum of numbers in [1, m] NOT divisible by n,
and B = sum of numbers in [1, m] divisible by n. Return A - B.

Example:
m = 10, n = 3
Output: 19
*/

import java.util.*;

public class DifferenceOfSums{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        int A=0,B=0;
        for(int i=1;i<=m;i++){
            if(i%n==0){
                B+=i;
            }else{
                A+=i;
            }
        }
        int C=A-B;
        System.out.println(C);

        sc.close();
    }
}
