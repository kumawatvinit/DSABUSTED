// package Amdocs_16_VILT_1;
import java.util.Scanner;

public class first {

    static int noOfDigits(int n)
    {
        int count = 0;
        while (n > 0) {
            count++;
            n /= 10;
        }
        return count;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int i = noOfDigits(n), sum = 0, num = n;

        while (num > 0) {
            sum += Math.pow(num % 10, i);
            num /= 10;
            i--;
        }

        if (sum == n)
            System.out.println("Disarium Number");
        else
            System.out.println("Not a Disarium Number");

        sc.close();
    }
}
