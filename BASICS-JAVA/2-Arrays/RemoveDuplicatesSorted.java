/*
Remove Duplicates from Sorted Array

Given a sorted array, keep each value once (in place) and return the new length.

Example:
arr = [1, 1, 2, 2, 3]
Output: 3   (array starts with [1, 2, 3])
*/
import java.util.*;

public class RemoveDuplicatesSorted{
    static int solve(int [] arr){
        int n=arr.length;
        int j=0;
        for(int i=0;i<n;i++){
            if(j<1 || arr[i]!=arr[j-1]){
                arr[j]=arr[i];
                j++;
            }
        }
        return j;

    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int [] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int res=solve(arr);
        System.out.println(res);
        sc.close();
    }
}