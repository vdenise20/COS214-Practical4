#include "DeliveryTruck.h"

void DeliveryTruck::callTruck() {
    if (isPurchased) {
        std::cout << "DeliveryTruck: Received notification to pick up harvested crops.\n";
        startEngine();  // Start the truck's operation
    }
    else {
        std::cout << "DeliveryTruck: This truck hasn't been purchased yet.\n";
    }
}

void DeliveryTruck::startEngine() {
    std::cout << R"(
              _______________
             |               |
             |  Delivery      |
             |     Truck!     |
             |_______________|
                |         |
              __|         |__
             |__|         |__|
        DeliveryTruck: Starting engine to collect harvested crops!
        )" << std::endl;
}

void DeliveryTruck::buyTruck() {
    isPurchased = true;
    std::cout << "DeliveryTruck has been purchased and is ready for operation.\n";
}

void DeliveryTruck::sellTruck() {
    isPurchased = false;
    std::cout << "DeliveryTruck has been sold and is no longer available.\n";
}
