// package Amdocs_16_VILT_1;
import java.util.Scanner;

public class fourth {

    static boolean isPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    static int reverse(int n) {
        int rev = 0;
        while (n != 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        return rev;
    }

    public static void main(String[] args) {
        // check whether the number is a twistedprime prime no. or not

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        sc.close();

        if (isPrime(n)) {
            int rev = reverse(n);
            if (isPrime(rev)) {
                System.out.println("Twisted Prime");
            } else {
                System.out.println("Not a Twisted Prime");
            }
        } else {
            System.out.println("Not a Twisted Prime");
        }

    }
}
