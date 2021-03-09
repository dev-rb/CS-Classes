#include "Car.hpp"
#include "Motorcycle.hpp"
#include "Bus.hpp"
#include "Truck.hpp"
#include "Garage.hpp"
#include "Vehicle.hpp"

#include <iostream>

int main()
{

    Car car("R8", "Audi", 295, 100, 20);
    Car car_one("BMW i8", "BMW", 295, 100, 20);
    Vehicle *car_two = new Car("Aventador", "Lambo", 295, 100, 20);
    Motorcycle moto("Yamaha R6", "Yamaha", 495, 60, 10);
    Bus bus("Bus", "Toyota", 95, 120, 40, 10);
    Truck truck("Truck", "Honda", 125, 400, 50, 500);
    Garage garage = Garage(12);

    std::cout << garage.addVehicle(car) << std::endl;

    std::cout << garage.addVehicle(bus) << std::endl;

    std::cout << "Swapping Audi for BMW " << garage.swapVehicles(car_one, car) << std::endl;

    garage.display();

    std::cout << "Swapping Bus for Yamaha " << garage.swapVehicles(moto, bus) << std::endl;
    garage.display();

    return 0;
}