#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
class SoilState;
class CropField : public FarmUnit
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
    void updateCurrentCrops(int num) override;
    int getYield() override;
    std::string getName() const;
    std::string getSoilStateName() const;
    SoilState* getState() override;
    void setState(SoilState* newState) override;
    int getLeftOverCapacity() override;
    void increaseProduction() override;
    void harvest() override;
    void harvestCrops();
    void rain() override;
};
#endif /* CROPFIELD_H */
