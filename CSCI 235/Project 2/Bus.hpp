#ifndef BUS_
#define BUS_

#include <iostream>
#include "Vehicle.hpp"

class Bus : public Vehicle
{
private:
    double total_seat_count;

public:
    Bus(std::string name, std::string manufacturer, double top_speed, double weight, double mpg, size_t number_seats);

    size_t getNumSeats() const;
};

#endif