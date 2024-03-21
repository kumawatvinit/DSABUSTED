// package Amdocs_16_VILT_1;
import java.util.Scanner;

public class third {
    public static void main(String[] args) {
        // whether a number is automorphic or not
        // last digits of square of a number is equal to the number itself
        // 6 = 36, 25 = 625

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.close();

        int square = n * n;
        int count = String.valueOf(n).length();

        int lastDigits = (int) (square % Math.pow(10, count));

        if (lastDigits == n)
            System.out.println("Automorphic Number");
        else
            System.out.println("Not an Automorphic Number");
    }
}
