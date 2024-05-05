// Write a program to accept the string from user and perform the menu driven operations
// 1. Display word with highest length
// 2. Display all palindrome words from the string
// 3. Display the words from the string which consists of any vowels.

import java.util.Scanner;

public class one {

    public static void displayWordWithHighestLength(String[] str) {
        int max = 0;
        String word = "";
        for (String s : str) {
            if (s.length() > max) {
                max = s.length();
                word = s;
            }
        }
        System.out.println("Word with highest length is: " + word);
    }

    public static boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) return false;
            
            i++; j--;
        }

        return true;
    }

    public static void displayAllPalindromeWords(String[] str) {
        int count = 0;

        for (String s : str) {
            if (isPalindrome(s)) {
                count++;
                System.out.println(s);
            }
        }

        if (count == 0) {
            System.out.println("No palindrome words found.");
        }
    }

    public static void displayWordsWithVowels(String[] str) {
        int count = 0;
        for (String s : str) {
            if (s.contains("a") || s.contains("e") || s.contains("i") || s.contains("o") || s.contains("u")
                    || s.contains("A") || s.contains("E") || s.contains("I") || s.contains("O") || s.contains("U") ) {
                count++;
                System.out.println(s);
            }
        }

        if (count == 0) {
            System.out.println("No words with vowels found.");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string");
        String[] str = sc.nextLine().split(" ");

        
        
        System.out.println("\n1. Display word with highest length");
        System.out.println("2. Display all palindrome words from the string");
        System.out.println("3. Display the words from the string which consists of any vowels.");
        System.out.println("4. Exit the program.");
        System.out.print("Enter your choice: ");
        
        
        while(true) {
            int choice = sc.nextInt();
            
            switch (choice) {
                case 1:
                    displayWordWithHighestLength(str);
                    break;
                case 2:
                    displayAllPalindromeWords(str);
                    break;
                case 3:
                    displayWordsWithVowels(str);
                    break;
                case 4:
                    sc.close();
                    System.exit(0);
            }
        }

    }
}