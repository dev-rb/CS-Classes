#include "Bus.hpp"

Bus::Bus(std::string name, std::string manufacturer, double top_speed, double weight, double mpg, size_t number_seats) : Vehicle(name, manufacturer, top_speed, weight, mpg, 0)
{
    total_seat_count = number_seats;
    setGarageSpaces(4);
    setNumWheels(8);
}

size_t Bus::getNumSeats() const
{
    return total_seat_count;
}