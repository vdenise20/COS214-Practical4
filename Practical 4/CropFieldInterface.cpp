#include "CropFieldInterface.h"
#include "Truck.h"
void CropFieldInterface::attach(Truck* observer) {
    observerList.push_back(observer);
    std::cout << "A truck has been attached to the CropField.\n";
}

void CropFieldInterface::detach(Truck* observer) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
    std::cout << "A truck has been detached from the CropField.\n";
}

void CropFieldInterface::notify(std::string name) {
    std::cout << "Notifying trucks...\n";
    for (Truck* observer : observerList) {
        if (observer->getName() == name)
            observer->callTruck();  // Trigger truck's callTruck method
    }
}