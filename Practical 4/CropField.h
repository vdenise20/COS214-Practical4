#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "CropFieldInterface.h"
class SoilState;
class CropField : public FarmUnit, public CropFieldInterface
{
private:
    std::string cropType;
    int totalCapacity;
    int currentStoredCrops;
    int yield;
    SoilState* currentState;

public:
    CropField(std::string name, std::string cropType, SoilState* currentState);
    std::string getCropType();
    int getTotalCapacity() const override;
    void updateCurrentCrops(int num);
    int getYield();
    std::string getName() const;
    std::string getSoilStateName() const;
    SoilState* getState();
    void setState(SoilState* newState);
    int getLeftOverCapacity() override;
    void increaseProduction() override;
    void harvest() override;
    void harvestCrops();
    void rain() override;
};
#endif /* CROPFIELD_H */
