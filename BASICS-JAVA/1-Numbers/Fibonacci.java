/*
Fibonacci Series

Print the first n Fibonacci numbers starting from 0.

Example:
n = 7
Output: 0 1 1 2 3 5 8
*/

import java.util.*;

public class Fibonacci{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            System.out.print(fib(i)+" ");
        }
        System.out.println();
        sc.close();
    }

    public static long fib(int n){
        if(n<=1){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
}
