#ifndef CAR_
#define CAR_

#include "Vehicle.hpp"
#include <iostream>

class Car : public Vehicle
{
public:
    Car(std::string name, std::string manufacturer, double top_speed, double weight, double mpg);
};

#endif