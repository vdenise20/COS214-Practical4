#ifndef BARN_H
#define BARN_H
#include "FarmUnit.h"
class Barn :
    public FarmUnit
{
private:
    int totalCapacity;

public: 
    int getTotalCapacity() const override;
    string getName() const override;
};
#endif /*BARN_H*/

