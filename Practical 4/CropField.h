#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "CropFieldInterface.h"

class SoilState;
class CropField :
    public FarmUnit, public CropFieldInterface
{
private:
    string cropType;
    int totalCapacity;
    int currentStoredCrops;
    int yield;
    SoilState* currentState;

public:
    CropField(string name, string cropType, SoilState* currentState);
    string getCropType();
    int getTotalCapacity() const override;
    void updateCurrentCrops(int num) override;
    int getYield();
    string getName() const;
    string getSoilStateName() const override;
    SoilState* getState();
    void setState(SoilState* newState);
    int getLeftOverCapacity() override;
    void increaseProduction() override;
    void harvest() override;
    void harvestCrops();
    void rain();
};
#endif /*CROPFIELD_H*/

