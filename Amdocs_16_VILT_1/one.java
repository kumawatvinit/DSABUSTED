import java.util.Scanner;

public class one {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int size = sc.nextInt();
        int[] arr = new int[size];

        for(int i=0; i<size; i++) {
            arr[i] = sc.nextInt();
        }

        sc.close();


        // second highest element
        int max = arr[0];
        int secondMax = Integer.MIN_VALUE;

        for(int i=1; i<size; i++) {
            if(arr[i] > max) {
                secondMax = max;
                max = arr[i];
            } else if(arr[i] > secondMax && arr[i] != max) {
                secondMax = arr[i];
            }
        }

        if(secondMax == Integer.MIN_VALUE) {
            System.out.println("No second highest element");
        } else {
            System.out.println("Second highest element: " + secondMax);
        }
        
    }
}