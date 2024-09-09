#ifndef FERTILISERTRUCK_H
#define FERTILISERTRUCK_H
#include "Truck.h"
class FertiliserTruck :
    public Truck
{
private:
    SoilState* observerState;
    CropField* subject;
    bool isPurchased;

public:
    FertiliserTruck() : Truck("Fertiliser") { isPurchased = false; }
    void callTruck() override;
    void startEngine() override;
    void buyTruck() override;
    void sellTruck() override;
};
#endif /*FERTILISERTRUCK_H*/

