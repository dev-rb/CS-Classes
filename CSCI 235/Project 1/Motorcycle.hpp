#ifndef MOTORCYCLE_
#define MOTORCYCLE_

#include "Vehicle.hpp"
#include <iostream>

class Motorcycle : public Vehicle
{
public:
    Motorcycle(std::string name, std::string manufacturer, double top_speed, double weight, double mpg);
};

#endif