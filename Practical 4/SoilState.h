#ifndef	SOILSTATE_H
#define SOILSTATE_H
#include "CropField.h"
#include <iostream>
using namespace std;

class CropField;
class SoilState
{
public:
	virtual void harvestCrops(CropField* field) = 0;
	virtual void rain(CropField* field) = 0;
	virtual string getName() = 0;
};
#endif /*SOILSTATE_H*/

