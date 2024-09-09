#ifndef FRUITFULSTATE_H
#define FRUITFULSTATE_H
#include "SoilState.h"
class FruitfulSoil :
    public SoilState
{
public: 
    void harvestCrops(CropField* field) override;
    void rain(CropField* field) override;
    string getName();
};
#endif /*FRUITFUL_H*/

