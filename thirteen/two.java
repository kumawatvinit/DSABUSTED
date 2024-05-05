package thirteen;

public class two {
    boolean isNiven(int num) {
        int sum = 0;
        int temp = num;

        while(temp > 0) {
            sum+= temp % 10;
            temp /= 10;
        }

        return num%sum == 0;
    }

    boolean isSpy(int num) {
        int sum = 0, product = 1;

        while(num > 0) {
            int digit = num % 10;
            sum += digit;
            product *= digit;
            num /= 10;
        }

        return sum == product;
    }

    boolean isUnique(int num) {
        boolean[] digits = new boolean[10];

        while(num > 0) {
            int digit = num % 10;
            if(digits[digit]) return false;
            digits[digit] = true;
            num /= 10;
        }

        return true;
    }

    public static void main(String[] args) {
        two obj = new two();

        System.out.println(obj.isNiven(12));
        System.out.println(obj.isNiven(13));

        System.out.println(obj.isSpy(1412));
        System.out.println(obj.isSpy(141));

        System.out.println(obj.isUnique(142));
        System.out.println(obj.isUnique(1412));
    }
}
