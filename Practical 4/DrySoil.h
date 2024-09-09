#ifndef DRYSOIL_H
#define DRYSOIL_H

#include <iostream>
using namespace std;

#include "SoilState.h"
class DrySoil :
    public SoilState
{
public:
    void harvestCrops(CropField* field) override;
    void rain(CropField* field) override;
    string getName() override;
};
#endif /*DRYSOIL_H*/

