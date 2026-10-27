/*
Move Zeros

Move all 0s to the end, keeping the order of the non-zero elements.

Example:
arr = [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
*/
import java.util.*;

public class MoveZeros{
    static void MoveZeroes(int [] arr){
        int n=arr.length;
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                arr[j]=arr[i];
                j++;
            }
        }
        for(int i=j;i<n;i++){
            arr[i]=0;
        }
        
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int [] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        sc.close();
        MoveZeroes(arr);
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+ " ");
        }

    }
}
