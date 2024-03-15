/**
 * Main
 */
/**
 * A
 */
class A {
    public A() {
        System.out.println("A");
    }

}

public class Main extends A {

    public Main() {
        System.out.println("Main");
        // super();
    }

    public static void main(String[] args) {
        new Main();
    }
}