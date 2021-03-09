#ifndef GARAGE_
#define GARAGE_

#include <iostream>
#include "Vehicle.hpp"

class Garage
{
private:
    void arrange();

    Vehicle *arr_;

    size_t capacity_;

    size_t num_vehicles_;

public:
    Garage(size_t capacity);

    bool addVehicle(Vehicle to_add);

    bool removeVehicle(Vehicle to_remove);

    bool swapVehicles(Vehicle swap_in, Vehicle swap_out);

    bool isFull() const;

    void displayAll() const;

    void display() const;
};

#endif