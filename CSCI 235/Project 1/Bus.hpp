#ifndef BUS_
#define BUS_

#include "Vehicle.hpp"
#include <iostream>

class Bus : public Vehicle
{

private:
    double number_seats_;

public:
    Bus(std::string name, std::string manufacturer, double top_speed, double weight, double mpg, size_t number_seats);

    size_t getNumSeats() const;
};

#endif