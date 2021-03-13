#include "Garage.hpp"
#include <vector>
#include <iostream>

template <typename ItemType>
Garage<ItemType>::Garage(size_t capacity)
{
    capacity_ = capacity;
    spaces_occupied_ = 0;
    items_ = new ItemType[capacity];
}

template <typename ItemType>
size_t Garage<ItemType>::getCurrentSize() const
{
    return spaces_occupied_;
}

template <typename ItemType>
bool Garage<ItemType>::isEmpty() const
{
    return spaces_occupied_ == 0;
}

template <typename ItemType>
bool Garage<ItemType>::add(const ItemType &to_add)
{
    // Check if there is space in the array to add.
    bool can_add = spaces_occupied_ < capacity_;

    if (can_add)
    {
        // Add in space and increment spaces_occupied_.
        items_[spaces_occupied_] = to_add;
        spaces_occupied_ += to_add.getSpaces();
    }

    return can_add;
}

template <typename ItemType>
bool Garage<ItemType>::remove(const ItemType &to_remove)
{
    // Get the index of the item we want to remove from the array.
    int index_of_item = getIndexOf(to_remove);
    // Check if we can remove it.
    bool can_remove = !isEmpty() && index_of_item > -1;

    if (can_remove)
    {
        spaces_occupied_ -= to_remove.getSpaces();
        items_[index_of_item] = items_[spaces_occupied_];
    }

    return can_remove;
}

template <typename ItemType>
bool Garage<ItemType>::swap(ItemType in, ItemType out)
{
    // Remove the item and add the new one in.
    return remove(out) && add(in);
}

template <typename ItemType>
int Garage<ItemType>::getFrequencyOf(const ItemType &an_entry) const
{
    int frequency = 0;

    for (int i = 0; i < capacity_; i++)
    {
        if (items_[i] == an_entry)
        {
            frequency++;
        }
    }

    return frequency;
}

template <typename ItemType>
std::vector<ItemType> Garage<ItemType>::toVector() const
{
    std::vector<ItemType> contents;

    for (int i = 0; i < capacity_; i++)
    {
        if (!items_[i].getName().empty())
        {
            contents.push_back(items_[i]);
        }
    }

    return contents;
}

template <typename ItemType>
bool Garage<ItemType>::isFull() const
{
    return spaces_occupied_ == capacity_;
}

template <typename ItemType>
void Garage<ItemType>::clear()
{
    spaces_occupied_ = 0;
}

template <typename ItemType>
bool Garage<ItemType>::contains(const ItemType &an_entry) const
{
    return getIndexOf(an_entry) != -1;
}

template <typename ItemType>
void Garage<ItemType>::display() const
{
    ItemType prev;
    for (int i = 0; i < spaces_occupied_; i++)
    {
        // Make sure that the item we are checking hasn't been printed and is not an empty item.
        if (items_[i] != prev && (!items_[i].getName().empty()))
        {
            std::cout << items_[i].getName() << " " << items_[i].getManufacturer() << std::endl;
            prev = items_[i];
        }
    }
}

template <typename ItemType>
void Garage<ItemType>::operator+=(const Garage<ItemType> &a_garage)
{
    int curr_idx = 0;
    // Make sure that the array is not full and loop through to check if we don't have a certain item and add that one in.
    // Set Union Operation.
    while (curr_idx < spaces_occupied_ && !isFull())
    {
        if (!contains(a_garage.items_[curr_idx]))
        {
            this->add(a_garage.items_[curr_idx]);
        }

        curr_idx++;
    }
}

template <typename ItemType>
void Garage<ItemType>::operator-=(const Garage<ItemType> &a_garage)
{
    int curr_idx = 0;
    // Check if we can subtract from the array and make sure it's not empty. Then we loop through and remove any items that we do have from the other array.
    // Set Difference Operation.
    while (curr_idx < spaces_occupied_ && !isEmpty())
    {
        if (contains(a_garage.items_[curr_idx]))
        {
            this->remove(a_garage.items_[curr_idx]);
        }

        curr_idx++;
    }
}

template <typename ItemType>
void Garage<ItemType>::operator/=(const Garage<ItemType> &a_garage)
{
    int curr_idx = 0;
    // Check if we can divide the array and remove items that are not shared. Then we loop through and remove items that are not in the other array.
    // Set Intersection Operation.
    while (curr_idx < spaces_occupied_ && !isEmpty())
    {
        if (!a_garage.contains(items_[curr_idx]))
        {
            this->remove(items_[curr_idx]);
        }

        curr_idx++;
    }
}

template <typename ItemType>
int Garage<ItemType>::getIndexOf(const ItemType &target) const
{
    size_t index = -1;
    bool found = false;

    for (int i = 0; i < capacity_; i++)
    {
        if (items_[i] == target && !found)
        {
            found = true;
            index = i;
        }
    }

    return index;
}
