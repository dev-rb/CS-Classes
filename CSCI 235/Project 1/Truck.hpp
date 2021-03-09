#ifndef TRUCK_
#define TRUCK_

#include "Vehicle.hpp"
#include <iostream>

class Truck : public Vehicle
{

private:
    double cargo_capacity_;
    double weight_of_held_cargo_;

public:
    Truck(std::string name, std::string manufacturer, double top_speed, double weight, double mpg, double cargo_capacity);

    bool add_cargo(double weight_of_cargo);

    bool clear();

    double getCargoCapacity() const;

    double getHeldCargoWeight() const;
};

#endif