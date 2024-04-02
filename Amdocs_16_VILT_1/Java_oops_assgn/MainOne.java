class Vehicle {
    String brand;
    int year;

    Vehicle(String brand, int year) {
        this.brand = brand;
        this.year = year;
    }

    void display() {
        System.out.println("Brand: " + brand);
        System.out.println("Year: " + year);
    }
}

class Car extends Vehicle {
    int numberOfDoors;

    Car(String brand, int year, int numberOfDoors) {
        super(brand, year);
        this.numberOfDoors = numberOfDoors;
    }

    @Override
    void display() {
        super.display();
        System.out.println("Number of doors: " + numberOfDoors);
    }
}

public class MainOne {
    public static void main(String[] args) {
        Car myCar = new Car("Toyota", 2022, 4);
        myCar.display();
    }
}
