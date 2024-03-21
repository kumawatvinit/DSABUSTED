// package Amdocs_16_VILT_1;
import java.util.Scanner;

public class second {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.close();
        
        String[] words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        String result = "";

        while (n > 0) {
            int digit = n % 10;
            result = words[digit] + " " + result;
            n /= 10;
        }

        System.out.println(result);

    }
}
