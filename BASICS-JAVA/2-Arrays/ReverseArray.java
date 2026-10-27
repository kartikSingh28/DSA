/*
Reverse Array (in place)

Reverse the array without using another array.

Example:
arr = [1, 2, 3, 4]
Output: [4, 3, 2, 1]
*/

import java.util.*;

public class ReverseArray{

    static void swap(int [] a,int i,int j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    static int [] solve(int [] nums){
        int n=nums.length;
        for(int i=0,j=n-1;i<j;i++,j--){
            swap(nums,i,j);

        }
        return nums;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int [] nums=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        int [] res=solve(nums);
        sc.close();
        for(int i=0;i<n;i++){
            System.out.print(res[i]+ " ");
        }

    }
}
