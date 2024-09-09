#ifndef DELIVERYTRUCK_H
#define DELIVERTRUCK_H
#include "Truck.h"
class DeliveryTruck :
    public Truck
{
private:
    SoilState* observerState;
    CropField* subject;
    bool isPurchased;

public:
    DeliveryTruck() : Truck("Delivery") { isPurchased = false; }
    void callTruck() override;
    void startEngine() override;
    void buyTruck() override;
    void sellTruck() override;
};
#endif /*DELIVERYTRUCK_H*/

