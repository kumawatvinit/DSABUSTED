interface Shape {
    double calculateArea();
    double calculatePerimeter();
}

class Circle implements Shape {
    private double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }
}

class Rectangle implements Shape {
    private double length;
    private double width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double calculateArea() {
        return length * width;
    }

    @Override
    public double calculatePerimeter() {
        return 2 * (length + width);
    }
}

class ShapeCalculator {
    private Shape shape;

    ShapeCalculator(Shape shape) {
        this.shape = shape;
    }

    void displayDetails() {
        System.out.println("Area: " + shape.calculateArea());
        System.out.println("Perimeter: " + shape.calculatePerimeter());
    }
}

public class MainTwo {
    public static void main(String[] args) {
        Circle circle = new Circle(7);
        Rectangle rectangle = new Rectangle(4, 6);

        ShapeCalculator circleCalculator = new ShapeCalculator(circle);
        ShapeCalculator rectangleCalculator = new ShapeCalculator(rectangle);

        System.out.println("Circle Details:");
        circleCalculator.displayDetails();
        System.out.println();

        System.out.println("Rectangle Details:");
        rectangleCalculator.displayDetails();
    }
}
