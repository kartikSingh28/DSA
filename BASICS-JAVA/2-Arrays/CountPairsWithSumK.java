/*
Count Pairs with Sum K

Count pairs (i < j) such that arr[i] + arr[j] == k.

Example:
arr = [1, 5, 7, 1], k = 6
Output: 2
*/
import java.util.*;

public class CountPairsWithSumK{
     static int  solve(int [] arr,int k){
        int n=arr.length;
        int i=0,j=n-1;
        int count=0;
        while(i<j){
            if(arr[i]+arr[j]==k){
                count++;
                i++;
                j--;
            }else if(arr[i]+arr[j]<k){
                i++;
            }else{
                j--;
            }
        }
        return count;

    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int [] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt(i);
        }
        int res=solve(arr,k);
        sc.close();
    }
}