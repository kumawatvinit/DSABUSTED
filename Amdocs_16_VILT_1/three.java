import java.util.Scanner;

public class three {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int row = sc.nextInt(), col = sc.nextInt();
        
        int[][] arr = new int[row][col];

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        sc.close();

        int sum = 0;
        for(int i=0; i<row; i++) {
            sum += arr[i][i];
        }

        System.out.println("Sum of major diagonal: " + sum);
    
    }
}
