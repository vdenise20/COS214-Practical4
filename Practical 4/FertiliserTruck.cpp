#include "FertiliserTruck.h"

void FertiliserTruck::callTruck() {
    if (isPurchased) {
        std::cout << "FertilizerTruck: Received notification to deliver fertilizer.\n";
        startEngine();  // Start the truck's operation
    }
    else {
        std::cout << "FertilizerTruck: This truck hasn't been purchased yet.\n";
    }
}

void FertiliserTruck::startEngine() {
    std::cout << R"(
              _______________
             |               |
             |  Fertilizing   |
             |     Truck!     |
             |_______________|
                |         |
              __|         |__
             |__|         |__|
        FertilizerTruck: Starting engine to deliver fertilizer!
        )" << std::endl;
}

void FertiliserTruck::buyTruck() {
    isPurchased = true;
    std::cout << "FertilizerTruck has been purchased and is ready for operation.\n";
}

void FertiliserTruck::sellTruck() {
    isPurchased = false;
    std::cout << "FertilizerTruck has been sold and is no longer available.\n";
}
