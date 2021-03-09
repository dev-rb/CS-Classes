#include "Garage.hpp"
#include "Vehicle.hpp"

#include <vector>
#include <iostream>
using namespace std;

int main()
{

    Garage<Vehicle> test(20);

    Bus bus("Bus", "Toyota", 200, 110, 10, 40);
    Bus busOne("Bus1", "Honda", 200, 110, 10, 40);
    Car car("Aventador", "Lambo", 400, 10, 20);
    Car carOne("R8", "Audi", 100, 10, 20);

    test.add(bus);

    test.add(car);
    test.add(carOne);

    test.display();

    vector<Vehicle> out = test.toVector();

    for (int i = 0; i < 12; i++)
    {
        cout << out[i].getName() << ", ";
    }

    return 0;
}