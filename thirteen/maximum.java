package thirteen;

public class maximum {

    int max(int a, int b) {
        return a > b ? a : b;
    }

    float max(float a, float b, float c) {
        return a > b && a > c ? a : b > c ? b : c;
    }

    int max(int arr[], int size) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < size; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }

    public static void main(String[] args) {
        maximum obj = new maximum();

        System.out.println(obj.max(10, 20));
        System.out.println(obj.max(10.5f, 20.5f, 30.5f));

        int arr[] = { 34, 20, 87, 94, 50 };

        System.out.println(obj.max(arr, arr.length));
    }
    
}
