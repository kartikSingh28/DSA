/*
Equilibrium Index

Return the first index where the sum of elements on the left equals
the sum on the right (the element itself is not counted). Return -1 if none.

Example:
arr = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
*/
import java.util.*;

public class EquilibriumIndex{
    static int solve(int [] nums){
        int n=nums.length;
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        int leftSum=0;
        for(int i=0;i<n;i++){
            int rightSum=totalSum-leftSum-nums[i];
            if(leftSum==rightSum) return i;
            leftSum+=nums[i];
        }
        return -1;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int [] nums= new int[n];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        int idx=solve(nums);
        sc.close();
        System.out.println(idx);

    }
}