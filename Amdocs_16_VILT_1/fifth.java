import java.util.Scanner;

public class fifth {

    static boolean isPalindrome(String str) {
        int start = 0, end = str.length() - 1;

        while (start < end) {
            if (str.charAt(start) != str.charAt(end))
                return false;
            start++;
            end--;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();
        sc.close();

        String[] words = str.split(" ");

        for (String st : words) {
            if (isPalindrome(st))
                System.out.println(st);
        }

    }
}
