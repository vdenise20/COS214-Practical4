#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H
#include "SoilState.h"
class FloodedSoil :
    public SoilState
{
public: 
    void harvestCrops(CropField* field) override;
    void rain(CropField* field) override;
    string getName();
};
#endif /*FLOODEDSOIL_H*/

