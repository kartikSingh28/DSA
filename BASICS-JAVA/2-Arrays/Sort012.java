/*
Sort 0s, 1s and 2s

The array has only 0, 1 and 2. Sort it in one pass without using a sort function.

Example:
arr = [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
*/
import java.util.*;

public class Sort012{

    static void swap(int a [],int i,int j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    static int [] solve(int [] nums){
        int n=nums.length;
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                swap(nums,j,i);
                j++;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                swap(nums,j,i);
                j++;
            }
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
        sc.close();
        int [] res=solve(nums);
        for(int i=0;i<n;i++){
            System.out.print(res[i]+" ");
        }
    }
}
