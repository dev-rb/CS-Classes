#include "Motorcycle.hpp"
#include <iostream>

Motorcycle::Motorcycle()
{
    // Set the brand to be a random brand.
    brand_ = static_cast<bike_details::bike_brand>(rand() % 4);
    curr_acceleration_ = bike_details::NONE;
    curr_speed_ = 0;
    curr_direction_ = 0;
}

Motorcycle::Motorcycle(int kind_of_bike)
{
    // Set the brand to be the one passed in. Converting it from an int to an enum using casting.
    brand_ = static_cast<bike_details::bike_brand>(kind_of_bike);
    curr_acceleration_ = bike_details::NONE;
    curr_speed_ = 0;
    curr_direction_ = 0;
}

std::string Motorcycle::getDirection()
{
    if (curr_direction_ >= 360)
    {
        return "Out of bounds";
    }
    if (curr_direction_ == 90)
    {
        // North
        return "North";
    }
    else if (curr_direction_ < 90 && curr_direction_ > 0)
    {
        // North East
        return "Northeast";
    }
    else if (curr_direction_ == 0)
    {
        // East
        return "East";
    }
    else if (curr_direction_ > 270)
    {
        // South East
        return "Southeast";
    }
    else if (curr_direction_ == 270)
    {
        // South
        return "South";
    }
    else if (curr_direction_ < 270 && curr_direction_ > 180)
    {
        // South West
        return "Southwest";
    }
    else if (curr_direction_ == 180)
    {
        // West
        return "West";
    }
    else if (curr_direction_ < 180 && curr_direction_ > 90)
    {
        // North West
        return "Northwest";
    }

    return "East";
}

std::string Motorcycle::getBikeType()
{
    switch (brand_)
    {
    case 0:
        return "YAMAHA";
        break;
    case 1:
        return "DUCATI";
        break;
    case 2:
        return "HARLEY_DAVIDSON";
        break;
    case 3:
        return "KAWASAKI";
        break;
    default:
        return "YAMAHA";
    }
}

float Motorcycle::getSpeed()
{
    return curr_speed_;
}

float Motorcycle::getDistanceTraveled()
{
    return distance_traveled_;
}

int Motorcycle::getIntensity()
{
    return curr_acceleration_;
}

void Motorcycle::turn(float degrees)
{
    // Adjust degrees value to be within the constraint of -360 <= degrees <= 360
    if (degrees > 360)
    {
        degrees = (int)degrees % 360;
    }
    else if (degrees < -360)
    {
        degrees = ((int)degrees % 360);
    }

    curr_direction_ = curr_direction_ + degrees;
}

void Motorcycle::updateSpeed()
{
    curr_speed_ = (curr_acceleration_ / 8) + ((brand_)*17.64);
}

void Motorcycle::accelerate()
{
    if (curr_acceleration_ != bike_details::acceleration::HIGH)
    {
        // Increment by 44 to increase the acceleration and then call updateSpeed().
        curr_acceleration_ = static_cast<bike_details::acceleration>(curr_acceleration_ + 44);
        updateSpeed();
    }
}

void Motorcycle::brake()
{
    if (curr_acceleration_ != bike_details::acceleration::NONE)
    {
        // Decrement by 44 to decrease the acceleration and then call updateSpeed().
        curr_acceleration_ = static_cast<bike_details::acceleration>(curr_acceleration_ - 44);
        updateSpeed();
    }
}

float Motorcycle::ride(float duration)
{
    if (duration <= 0)
    {
        distance_traveled_ = 0;
        return distance_traveled_;
    }

    float dTraveled = curr_speed_ * duration;

    distance_traveled_ = distance_traveled_ + dTraveled;

    return dTraveled;
}