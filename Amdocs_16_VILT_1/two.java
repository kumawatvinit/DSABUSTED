import java.util.*;

public class two {

    static int longestConsecutive(int[] arr) {
        if(arr.length == 0) {
            return 0;
        }

        int max = 1, curr = 1;
        int prev = arr[0];

        for(int i=1; i<arr.length; i++) 
        {
            if(arr[i] == (prev+1)) {
                curr++;
            } else {
                max = Math.max(max, curr);
                curr = 1;
            }
            prev = arr[i];
        }

        max = Math.max(max, curr);
        return max;
    } 
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int size = sc.nextInt();
        int[] arr = new int[size];

        for(int i=0; i<size; i++) {
            arr[i] = sc.nextInt();
        }

        sc.close();
        Arrays.sort(arr);
        
        for(int i=0; i<size; i++) {
            System.out.print(arr[i] + " ");
        }

        // longest consecutive sequence
        System.out.println("\nLongest consecutive sequence: " + longestConsecutive(arr));
        
    }
}