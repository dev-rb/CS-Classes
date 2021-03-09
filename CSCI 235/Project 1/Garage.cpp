#include "Garage.hpp"
#include "cmath"

namespace null
{
    Vehicle v;
}

Garage::Garage(size_t capacity = 12)
{
    capacity_ = capacity;
    num_vehicles_ = 0;
    arr_ = NULL;
}

void Garage::arrange()
{
    Vehicle *newArr = new Vehicle[num_vehicles_];

    int num_null = 0;
    int not_null = 0;
    for (int i = 0; i < num_vehicles_; i++)
    {

        if (arr_[i] != null::v)
        {
            newArr[not_null] = arr_[i];
            not_null += 1;
        }
        else
        {
            num_null += 1;
        }
    }

    for (int i = not_null; i < num_vehicles_; i++)
    {
        newArr[i] = null::v;
    }
    delete[] arr_;
    arr_ = newArr;
}

bool Garage::addVehicle(Vehicle to_add)
{
    if (isFull() || (num_vehicles_ + to_add.getSpaces()) > capacity_)
    {
        return false;
    }

    num_vehicles_ += to_add.getSpaces();

    if (arr_ == NULL)
    {
        arr_ = new Vehicle[num_vehicles_];
        for (int i = 0; i < num_vehicles_; i++)
        {
            arr_[i] = to_add;
        }
    }
    else
    {

        Vehicle *temp = new Vehicle[num_vehicles_];

        for (int i = 0; i < num_vehicles_ - to_add.getSpaces(); i++)
        {

            temp[i] = arr_[i];
        }

        delete[] arr_;

        for (int i = num_vehicles_ - to_add.getSpaces(); i < num_vehicles_; i++)
        {
            temp[i] = to_add;
        }

        arr_ = temp;
    }

    return true;
}

bool Garage::removeVehicle(Vehicle to_remove)
{
    if (num_vehicles_ == 0)
    {
        return false;
    }

    for (int i = 0; i < num_vehicles_; i++)
    {
        if (arr_[i] == to_remove)
        {
            arr_[i] = null::v;
        }
    }

    arrange();
    num_vehicles_ -= to_remove.getSpaces();

    return true;
}

bool Garage::swapVehicles(Vehicle swap_in, Vehicle swap_out)
{
    return removeVehicle(swap_out) && addVehicle(swap_in);
}

bool Garage::isFull() const
{
    return num_vehicles_ == capacity_;
}

void Garage::display() const
{
    Vehicle prev = arr_[0];

    for (int i = 0; i < num_vehicles_; i++)
    {
        if (i == 0 && arr_[i] != null::v)
        {
            std::cout << prev.getManufacturer() << " " << prev.getName() << std::endl;
        }
        else if ((arr_[i] != null::v && arr_[i] != prev))
        {
            std::cout << arr_[i].getManufacturer() << " " << arr_[i].getName() << std::endl;
            prev = arr_[i];
        }
    }
}

void Garage::displayAll() const
{
    int count = 0;
    for (int i = 0; i < capacity_; i++)
    {
        if (arr_[i] == null::v)
        {
            count += 1;
            std::cout << "Null" << std::endl;
        }
        std::cout << arr_[i].getManufacturer() << " " << arr_[i].getName() << std::endl;
    }

    std::cout << "Empty: " << count;
}