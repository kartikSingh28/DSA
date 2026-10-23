import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // ---- Reading input ----
        int n = sc.nextInt();              // one integer
        // long big = sc.nextLong();        // one big number
        // String word = sc.next();         // one word (stops at space)
        // sc.nextLine(); String line = sc.nextLine();  // a full line with spaces

        int[] arr = new int[n];            // n numbers into an array
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // ---- Solve ----
        int answer = solve(arr, n);

        // ---- Output ----
        System.out.println(answer);

        sc.close();
    }

    static int solve(int[] arr, int n) {
        int result = 0;
        // your logic here
        return result;
    }
}