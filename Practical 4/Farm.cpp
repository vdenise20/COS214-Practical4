#include "Farm.h"
#include <algorithm> // for std::remove

// Implement the getName() method
std::string Farm::getName() const {
    return FarmUnit::getName(); // Return the name of the farm
}

// Implement the getTotalCapacity() method
int Farm::getTotalCapacity() const {
    int totalCapacity = 0;

    // Iterate over all children (other farms or crop fields) and sum up their capacities
    for (const FarmUnit* unit : units) {
        totalCapacity += unit->getTotalCapacity();
    }

    return totalCapacity; // Return the total capacity of all child units
}

// Implement the add() method
void Farm::add(FarmUnit* unit) {
    units.push_back(unit); // Add a new farm unit (farm or crop field) to the children vector
}

// Implement the remove() method
void Farm::remove(FarmUnit* unit) {
    // Remove the unit from the children vector
    units.erase(std::remove(units.begin(), units.end(), unit), units.end());
}

// Implement the getChildren() method
std::vector<FarmUnit*> Farm::getChildren() {
    return units; // Return the vector of children (farms or crop fields)
}
