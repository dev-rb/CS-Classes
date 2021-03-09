#ifndef CAR_
#define CAR_

#include <iostream>
#include "Vehicle.hpp"

class Car : public Vehicle
{
public:
    Car(std::string name, std::string manufacturer, double top_speed, double weight, double mpg);
};

#endif