/*
Majority Element

Return the element that appears more than n/2 times (it always exists).

Example:
arr = [2, 2, 1, 1, 1, 2, 2]
Output: 2
*/

import java.util.*;

public class MajorityElement{
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];

        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        HashMap<Integer,Integer> freq=new HashMap<>();
        for(int x:arr){
            freq.put(x,freq.getOrDefault(x, 0)+1);
        }

        for(Map.Entry<Integer,Integer> e:freq.entrySet()){
            if(e.getValue()>n/2){
                System.out.println(e.getKey());
            }
        }
        sc.close();
    }
}