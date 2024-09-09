#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H
#include "SoilState.h"
class FloodedSoil :
    public SoilState
{
public: 
    void harvestCrops(FarmUnit* field) override;
    void rain(FarmUnit* field) override;
    string getName();
};
#endif /*FLOODEDSOIL_H*/

